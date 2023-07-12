#include <cmath>
#include <cstdlib>
#include <iostream>
#include "lib/nnue.hpp"
#include <vector>

#define DEBUG

char nnue_algorithm(char *pos, std::vector<std::vector<w_type>> &w_1, std::vector<std::vector<w_type>> &w_2, std::vector<w_type> &b_1, std::vector<w_type> &b_2){
    std::vector<w_type> neu(qtd_neu);
    mul_matrix(w_1,&pos,neu);
    sum_matrix(b_1,neu,neu);
    apply_sigmoid(neu);
    std::vector<w_type>results(qtd_out,0);
    mul_matrix(w_2,neu,results);
    sum_matrix(results,b_2,results);
    apply_sigmoid(results);
    impress_w(results);
    return 0;
}

void save_weight(std::string filename,std::vector<std::vector<w_type>> vector_){
    FILE *file_ptr=nullptr;

    const char *filename_ = filename.c_str();

    file_ptr = fopen(filename_,"w+b");

    if(!(file_ptr)){
        std::cout << "ERRO." << std::endl;
        exit(1);
    }

    w_type *aux = (w_type*) calloc(1,sizeof(w_type));

    for(int i = 0; i < vector_.size(); i++){
        for(int j = 0; j < vector_[0].size(); j++){
            *aux = vector_[i][j];
            fwrite(aux,sizeof(w_type),1,file_ptr);
        }
    }

    free(aux);
    fclose(file_ptr);
}

void save_weight(std::string filename,std::vector<w_type> vector_){
    FILE *file_ptr=nullptr;

    const char *filename_ = filename.c_str();

    file_ptr = fopen(filename_,"w+b");

    if(!(file_ptr)){
        std::cout << "ERRO." << std::endl;
        exit(1);
    }

    w_type *aux = (w_type*) calloc(1,sizeof(w_type));

    for(int i = 0; i < vector_.size(); i++){
        *aux = vector_[i];
        fwrite(aux,sizeof(w_type),1,file_ptr);
    }

    free(aux);
    fclose(file_ptr);
}

void load_weight(std::string filename,std::vector<std::vector<w_type>> &ref){
    FILE *file_ptr=nullptr;

    const char *filename_ = filename.c_str();

    file_ptr = fopen(filename_,"r+b");

    if(!(file_ptr)){
        std::cout << "ERRO." << std::endl;
        exit(1);
    }    

    std::vector<w_type> aux_v;
    w_type *aux_num = (w_type*) calloc(1,sizeof(w_type));

    for(int i = 0; i < ref.size(); i++){
        for(int j = 0; j < ref[0].size(); j++){
            fread(aux_num,sizeof(w_type),1,file_ptr);
            aux_v.push_back(*aux_num);
            //std::cout << *aux_num << std::endl;
        }
        ref[i] = (aux_v);
        aux_v.clear();
    }

    free(aux_num);
    fclose(file_ptr);
}

void load_weight(std::string filename,std::vector<w_type> &ref){
    FILE *file_ptr=nullptr;

    const char *filename_ = filename.c_str();

    file_ptr = fopen(filename_,"r+b");

    if(!(file_ptr)){
        std::cout << "ERRO." << std::endl;
        exit(1);
    }    

    w_type *aux_num = (w_type*) calloc(1,sizeof(w_type));

    for(int i = 0; i < ref.size(); i++){
        fread(aux_num,sizeof(w_type),1,file_ptr);
        ref[i] = *aux_num;
    }

    free(aux_num);
    fclose(file_ptr);
}

w_type _max(double num1,w_type num2){
    w_type res = 0;
    if(num1 > num2){
        res = num1;
    }
    else{
        res = num2;
    }
    return res;
}

void apply_relu(std::vector<w_type> &mat){
    for(int i = 0; i < mat.size(); i++){
        mat[i] = _max(0,mat[i]);
    }
}

void apply_sigmoid(std::vector<w_type> &mat){
    for(int i = 0; i < mat.size(); i++){
        mat[i] = sigmoid(mat[i]);
    }
}

double sigmoid (double x) {
    return 1 / (1 + exp (-x));
}

void fill_random(std::vector<std::vector<w_type>> &matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            matrix[i][j] = ((w_type)((rand()%200)-100))/100;
        }
    }
}

void fill_random(std::vector<w_type> &array){
    for(int i = 0; i < array.size(); i++){
        array[i] = ((w_type)((rand()%200)-100))/100;
    }
}

void impress_w(std::vector<std::vector<w_type>>mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            printf("%2.2f\t",mat[i][j]);
        }
        printf("\n");
    }
}

void impress_w(std::vector<w_type>mat){
    for(int i = 0; i < mat.size(); i++){
        printf("%2.2f ",mat[i]);
    }
    printf("\n");
}

int mul_matrix(std::vector<std::vector<w_type>> &mat1,char**mat2,std::vector<w_type>&res){
    if(mat1[0].size() != qtd_in){
        #ifdef DEBUG
        exit(1);
        #endif
        return 1;
    }

    for(int i = 0; i < mat1[0].size(); i++){
        for(int j = 0; j < qtd_in; j++){
            res[i]+=mat1[i][j]*(*mat2)[j];
        }
    }

    return 0;
}

int mul_matrix(std::vector<std::vector<w_type>> &mat1,std::vector<w_type> &mat2,std::vector<w_type> &res){
    if(mat1[0].size() != qtd_neu){
        #ifdef DEBUG
        exit(1);
        #endif
        return 1;
    }

    for(int i = 0; i < mat1.size(); i++){
        for(int j = 0; j < qtd_neu; j++){
            res[i]+=mat1[i][j]*mat2[j];
        }
    }

    return 0;
}

int sum_matrix(std::vector<w_type> &mat1,std::vector<w_type> &mat2,std::vector<w_type> &ref){
    if(mat1.size() != mat2.size()){
        #ifdef DEBUG
        exit(1);
        #endif
        return 1;
    }
    for(int i = 0; i < mat1.size(); i++){
        ref[i] = mat1[i]+mat1[i];
    }
    return 0;
}