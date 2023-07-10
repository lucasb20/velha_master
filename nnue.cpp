#include <cmath>
#include <cstdlib>
#include <iostream>
#include "lib/nnue.hpp"
#include <vector>

char nnue_algorithm(char *pos){
    w_type **weight_=nullptr, *bias=nullptr;
    weight_ = (w_type**) calloc(qtd_neu,sizeof(w_type*));
    bias = (w_type*) calloc(qtd_neu,sizeof(w_type));
    for(int i = 0; i < qtd_neu; i++){
        weight_[i] = (w_type*) calloc(qtd_in,sizeof(w_type));
    }
    fill_random(&weight_,qtd_neu,qtd_in);
    fill_random(&bias,qtd_neu);
    w_type *neu=nullptr;
    mul_matrix(&weight_,&pos,&neu,qtd_neu,qtd_in,qtd_in,1);
    sum_matrix(&bias,&neu,&neu,qtd_neu);
    apply_sigmoid(&neu,qtd_neu);
    w_type **weight_2=nullptr,*bias_2=nullptr;
    weight_2 = (w_type**) calloc(qtd_out,sizeof(w_type*));
    bias_2 = (w_type*) calloc(qtd_out,sizeof(w_type));
    for(int i = 0; i < qtd_out; i++){
        weight_2[i] = (w_type*) calloc(qtd_neu,sizeof(w_type));
    }
    fill_random(&weight_2,qtd_out,qtd_neu);
    fill_random(&bias_2,qtd_out);

    w_type* results;
    results = (w_type*) calloc(qtd_out,sizeof(w_type));

    mul_matrix(&weight_2,&neu,&results,qtd_neu,qtd_out,qtd_neu,1);
    sum_matrix(&results,&bias_2,&results,qtd_neu);

    impress_w(results,qtd_neu);

    return 0;
}

void apply_sigmoid(w_type **mat,size_t lin){
    for(int i = 0; i < lin; i++){
        (*mat)[i] = sigmoid((*mat)[i]);
    }
}

double sigmoid (double x) {
    return 1 / (1 + exp (-x));
}

void fill_random(w_type ***matrix, size_t lin, size_t col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            (*matrix)[i][j] = (double)((rand()%100)-100);
        }
    }
}

void fill_random(w_type **matrix, size_t lin){
    for(int i = 0; i < lin; i++){
        (*matrix)[i] = (double)((rand()%100)-100);
    }
}

void impress_w(w_type **mat,size_t lin, size_t col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%3f ",mat[i][j]);
        }
        printf("\n");
    }
}

void impress_w(w_type *mat,size_t lin){
    for(int i = 0; i < lin; i++){
        printf("%3f ",mat[i]);
    }
    printf("\n");
}

int mul_matrix(w_type*** mat1,char**mat2,w_type**mat3,size_t lin1, size_t col1, size_t lin2, size_t col2){
    if(col1 != lin2){
        return 1;
    }

    *mat3 = (w_type*) calloc(lin1,sizeof(w_type));

    for(int i = 0; i < lin1; i++){
        for(int j = 0; j < col1; j++){
            (*mat3)[i]+=(*mat1)[i][j]*(*mat2)[j];
        }
    }

    return 0;
}

int mul_matrix(w_type*** mat1,w_type**mat2,w_type**mat3,size_t lin1, size_t col1, size_t lin2, size_t col2){
    if(col1 != lin2){
        return 1;
    }

    *mat3 = (w_type*) calloc(lin1,sizeof(w_type));

    for(int i = 0; i < lin1; i++){
        for(int j = 0; j < col1; j++){
            (*mat3)[i]+=(*mat1)[i][j]*(*mat2)[j];
        }
    }

    return 0;
}

int sum_matrix(w_type**mat1,w_type**mat2,w_type**mat3,size_t lin){
    *mat3 = (w_type*) calloc(lin,sizeof(w_type));
    for(int i = 0; i < lin; i++){
        (*mat3)[i] = (*mat1)[i]+(*mat2)[i];
    }
    return 0;
}