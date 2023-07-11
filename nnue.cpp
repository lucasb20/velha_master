#include <cmath>
#include <cstdlib>
#include <iostream>
#include "lib/nnue.hpp"
#include <vector>

#define DEBUG

char nnue_algorithm(char *pos){
    std::vector<std::vector<w_type>> weight_ (qtd_neu, std::vector<w_type>(qtd_in));
    std::vector<w_type> bias(qtd_neu);
    fill_random(weight_);
    fill_random(bias);
    std::vector<w_type> neu(qtd_neu);
    mul_matrix(weight_,&pos,neu);
    sum_matrix(bias,neu,neu);
    apply_sigmoid(neu);
    std::vector<std::vector<w_type>> weight_2 (qtd_out, std::vector<w_type>(qtd_neu));
    std::vector<w_type> bias_2(qtd_out);
    fill_random(weight_2);
    fill_random(bias_2);
    std::vector<w_type>results(qtd_out,0);
    mul_matrix(weight_2,neu,results);
    sum_matrix(results,bias_2,results);
    apply_sigmoid(results);
    impress_w(results);

    return 0;
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
            matrix[i][j] = (double)((rand()%100)-100);
        }
    }
}

void fill_random(std::vector<w_type> &array){
    for(int i = 0; i < array.size(); i++){
        array[i] = (double)((rand()%100)-100);
    }
}

void impress_w(std::vector<std::vector<w_type>>mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }
}

void impress_w(std::vector<w_type>mat){
    for(int i = 0; i < mat.size(); i++){
        printf("%3f ",mat[i]);
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