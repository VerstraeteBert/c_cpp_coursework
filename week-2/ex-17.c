#include <stdio.h>

const int MAX_ROWS = 20;

void read_matrix(int matrix[][MAX_ROWS], int num_rows, int num_cols) {
    int i; int j;
    printf("Please enter %d numbers to create the matrix\n", num_cols * num_rows);
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix (int matrix[][MAX_ROWS], int num_rows, int num_cols) {
    int i = 0; int j = 0;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int matrix[][MAX_ROWS], int dimension) {
    int i; int j; int temp;
    for (i = 0; i < dimension; i++) {
        for (j = i + 1; j < dimension; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void multiply_matrix(int product[][MAX_ROWS], int matrix_1[][MAX_ROWS], int matrix_2[][MAX_ROWS], int dimension) {
    int accumulator;
    int i; int j; int k;
    for (i = 0; i < dimension; i++) {
        for (j = 0; j < dimension; j++) {
            accumulator = 0;
            for (k = 0; k < dimension; k++) {
                accumulator += matrix_1[i][k] * matrix_2[k][j];
            }
            product[i][j] = accumulator;
        }
    }
}

int main() {
    int matrix_read[][MAX_ROWS] = {};
    int matrix_one [][MAX_ROWS] = {
            { 1, 3, 7, 6 },
            { 2, 3, 1, 2 },
            { 5, 2, 3, 7 },
            { 2, 1, 3, 4 }
    };
    int matrix_two [][MAX_ROWS] = {
            { 4, 5, 7, 8 },
            { 2, 2, 3, 1 },
            { 6, 2, 4, 5 },
            { 1, 4, 5, 8 }
    };
    int result [][MAX_ROWS] = {};

    read_matrix(matrix_read, 3, 3);
    print_matrix(matrix_read, 3, 3);
    transpose_matrix(matrix_read, 3);
    print_matrix(matrix_read, 3, 3);
    multiply_matrix(result, matrix_one, matrix_two, 4);
    print_matrix(result, 4, 4);

    return 0;
}
