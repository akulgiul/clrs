/**
 * @file matrix.c
 * @author luka luig (luka@4luig.de)
 * @brief utility "class" for matrices, uses vector.c so that size can be determined at runtime
 * @date 2022-10-12
 *
 * Copyright (c) 2022 luka luig
 *
 */

#include "vector.c"

// dynamic sized matrices
typedef struct {
	int rows;
	int columns;
	Vector vector;
} Matrix;

// returns matrix with given size
Matrix make_matrix(int n_rows, int n_columns) {
	Matrix new_matrix;
	new_matrix.rows = n_rows;
	new_matrix.columns = n_columns;
	init_vector(&new_matrix.vector, n_rows * n_columns);
	return new_matrix;
}

// lets user input values for matrix
// column per column
void fill_matrix(Matrix *A) {
	int tmp;
	for (int i = 0; i < A->rows * A->columns; i++) {
		scanf("%d", &tmp);
		insert_vector(&(A->vector), tmp);
	}
}

// changes value at given position
void insert_element_matrix(Matrix *A, int value, int row, int column) {
	A->vector.vector[column * A->columns + row] = value;
}

// returns new matrix A*B
Matrix multiply_matrix(Matrix *A, Matrix *B) {
	// check for compatibility
	if (A->columns != B->rows) {
		printf("Sorry! These two matrices can't be multiplied.");
		return make_matrix(0, 0);
	}
	Matrix R = make_matrix(A->rows, B->columns);
	for (int y = 0; y < R.columns; y++) {
		for (int x = 0; x < R.rows; x++) {
			R.vector.vector[y * R.rows + x] = 0;
			for (int k = 0; k < A->columns; k++)
				R.vector.vector[y * R.rows + x] += A->vector.vector[k * A->rows + x] * B->vector.vector[y * B->rows + k];
		}
	}
	return R;
}

void print_matrix(Matrix *A) {
	for (int y = 0; y < A->rows; y++) {
		for (int x = 0; x < A->columns; x++)
			printf("%d ", A->vector.vector[x * A->rows + y]);
		printf("\n");
	}
	printf("\n");
}

// frees memory of vector of matrix, see free_vector(*vec) in vector.c
void free_matrix(Matrix *A) {
	free_vector(&(A->vector));
}