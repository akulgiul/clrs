/**
 * @file square_matrix_multiply.c
 * @author luka luig (luka@4luig.de)
 * @brief implementation of clrs algorithm: square matrix multiply, but generalized to any matrix dimensions
 * @date 2022-09-27
 *
 * Copyright (c) 2022 luka luig
 *
 */

#include "../helper.c"
#include "../matrix.c"

int main(void) {
	// let user determine size of matrices
	int a_row = input_int_min_max(1, 10, "Number of rows in matrix A");
	int a_column = input_int_min_max(1, 10, "Number of columns in matrix A (and rows in B)");
	int b_column = input_int_min_max(1, 10, "Number of columns in matrix B");

	Matrix A = make_matrix(a_row, a_column);
	printf("Please enter values for A:\n");
	fill_matrix(&A);

	Matrix B = make_matrix(a_column, b_column);
	printf("Please enter values for B:\n");
	fill_matrix(&B);

	printf("Matrix A:\n");
	print_matrix(&A);
	printf("Matrix B:\n");
	print_matrix(&B);
	printf("\n");

	printf("Matrix A*B:\n");
	Matrix C = multiply_matrix(&A, &B);
	print_matrix(&C);
}