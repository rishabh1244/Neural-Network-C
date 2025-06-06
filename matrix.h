#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct
{
    int row;
    int col;

    float **data;
} Matrix;


float generate_random_float();
int init_matrix(Matrix *m,int row , int col );
void matrix_free(Matrix *matrix);
int set_data(Matrix *matrix , int row_index , int col_index, double data);
int dot_product(const Matrix *m1, const Matrix *m2,Matrix *result);
void init_random(Matrix *matrix);
void view(Matrix *matrix );
double get_data(Matrix *matrix , int row_index , int col_index);
int init_weight(Matrix *matrix, int rows, int cols);
void set_zero(Matrix *matrix);
#endif