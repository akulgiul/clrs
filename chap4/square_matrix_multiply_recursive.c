/**
 * @file square_matrix_multiply_recursive.c
 * @author luka luig (luka@4luig.de)
 * @brief implementation of clrs algorithm: square Matrix multiply recursive
 * @date 2022-09-27
 *
 * @copyright Copyright (c) 2022 luka luig
 */

#include "../matrix.c"
#include <stdio.h>
#include <stdlib.h>

Matrix multiply_matrix_recursive(Matrix *A, Matrix *B);

int main(void) {
	int n = 2;
	Matrix A = make_matrix(n, n);
	Matrix B = make_matrix(n, n);

	printf("Please enter values for matrix A:\n");
	fill_matrix(&A);
	printf("Please enter values for matrix B:\n");
	fill_matrix(&B);


	printf("Matrix A:\n");
	print_matrix(&A);
	printf("Matrix B:\n");
	print_matrix(&B);
}

Matrix multiply_matrix_recursive(Matrix *A, Matrix *B) {
	int n = A->rows;
	Matrix C = make_matrix(n, n);
	if (n == 1)
		C.vector.vector[0] = A->vector.vector[0] * B->vector.vector[0];
	else {
		// partition matrices
		// C_1_1 = multiply_matrix_recursive(A_1_1, B_1_1);
		// etc.
	}
}
