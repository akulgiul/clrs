/**
 * @file matrix.c
 * @author luka luig (luka@4luig.de)
 * @brief utility "class" for matrices
 * @date 2022-10-12
 *
 * Copyright (c) 2022 luka luig
 *
 */

#include "vector.c"

typedef struct {
	int rows;
	int columns;
	Vector vector;
} Matrix;

Matrix make_matrix(int n_rows, int n_columns) {
	Matrix new_matrix;
	new_matrix.rows = n_rows;
	new_matrix.columns = n_columns;
	init_vector(&new_matrix.vector, n_rows * n_columns);
	return new_matrix;
}

void fill_matrix(Matrix *A) {
	// printf("reached fill_matrix with A.rows: %d\n", A->rows);
	int tmp;
	for (int i = 0; i < A->rows * A->columns; i++) {
		scanf("%d", &tmp);
		insert_vector(&(A->vector), tmp);
	}
}

void insert_element_matrix(Matrix *A, int value, int row, int column){
	A->vector.vector[column * A->columns + row] = value;
}

void print_matrix(Matrix *A) {
	for (int y = 0; y < A->rows; y++) {
		for (int x = 0; x < A->columns; x++)
			printf("%d ", A->vector.vector[x * A->rows + y]);
		printf("\n");
	}
	printf("\n");
}

void free_matrix(Matrix *A){
	free_vector(&(A->vector));
}

// int main() {
// 	Matrix A = make_matrix(2, 2);
// 	fill_matrix(&A);
// 	print_matrix(&A);
// }