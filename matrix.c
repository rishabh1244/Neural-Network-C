#include "matrix.h"

//initialisze a matrix for neural networks weight
int init_weight(Matrix *matrix, int rows, int cols){
    init_matrix(matrix,  rows,  cols);
    init_random(matrix);
    return 0;
}

int init_matrix(Matrix *matrix, int rows, int cols)
{
    matrix->row = rows;
    matrix->col = cols;
    matrix->data = (float **)malloc(rows * sizeof(float *));
    ;
    if (matrix->data == NULL)
    {
        printf("failed");
        return 0;
    }
    for (int i = 0; i < matrix->row; i++)
    {
        matrix->data[i] = (float *)malloc(cols * sizeof(float));
    }
    return 0;
}
void matrix_free(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
    matrix->row = 0;
    matrix->col = 0;
    matrix->data = NULL;
}

int set_data(Matrix *matrix, int row_index, int col_index, double data)
{
    matrix->data[row_index][col_index] = data;
}


void init_random(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            matrix->data[i][j] = generate_random_float();
        }
    }
}

void set_zero(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            matrix->data[i][j] = 0;
        }
    }
}

void view(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        printf("%d - \t", i);
        for (int j = 0; j < matrix->col; j++)
        {
            printf("%f\t", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double get_data(Matrix *matrix, int row_index, int col_index)
{
    return matrix->data[row_index][col_index];
}

float generate_random_float()
{
    return  ((double)rand() / RAND_MAX) * 2-1;
}

// Function to perform matrix multiplication
int dot_product(const Matrix *m1, const Matrix *m2, Matrix *result) {
    if (m1->col != m2->row) {
        printf("Matrix Multiplication failed: m1.col != m2.row\n");
        return 1;
    }

    if (init_matrix(result, m1->row, m2->col) != 0) {
        printf("Matrix initialization failed\n");
        return 1;
    }

    for (int i = 0; i < m1->row; i++) {
        for (int j = 0; j < m2->col; j++) {
            float sum = 0.0;
            for (int k = 0; k < m1->col; k++) {
                sum += m1->data[i][k] * m2->data[k][j];
            }
            set_data(result, i, j, sum);
        }
    }

    return 0;
}


/*
int dot_product(const Matrix *m1, const Matrix *m2,Matrix *result)
{
    // result= (Matrix*)(malloc(sizeof(Matrix)));

    printf("row %d \n",m1->col);
    printf("col %d\n",m2->row);

    if (m1->col != m2->row)
    {
        printf("Matrix Multiplication failed : m1.cl != m2.row \n");
        return 1;
    }

    if (init_matrix(result, m1->row, m2->col) != 0)
    {
        printf("Matrix initialization failed  \n");

        return 1;
    }

    for (int i = 0; i < m1->row; i++)
    {
        for (int j = 0; j < m2->col; j++)
        {
            float sum = 0.0;
            for (int k = 0; k < m1->col; k++)
            {
                sum += m1->data[i][k] * m2->data[k][j];
            }
            set_data(result, i, j, sum);
        }
    }

    return 0;
}*/