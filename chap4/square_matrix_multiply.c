/**
 * @file square_matrix_multiply.c
 * @author luka luig (luka@4luig.de)
 * @brief implementation of clrs algorithm: square matrix multiply
 * @date 2022-09-27
 *
 * @copyright Copyright (c) 2022 luka luig
 * licensed under the GNU General Public License v3.0
 *
 */

#include <stdio.h>

/**
 * @brief multiply 2 square matrices ||
 * @brief result matrix must be already be declared by the caller
 *
 * @param n size of square matrices
 * @param A n*n matrix
 * @param B n*n matrix
 * @param *result pointer to matrix assigned with result of A * B
 */
void multiply_square_matrix(int n, int A[n][n], int B[n][n], int (*result)[n][n]);

/**
 * @brief simple print function for 2D square matrices
 *
 * @param n size
 * @param matrix n*n matrix
 */
void print_2D_array(int n, int matrix[n][n]);

int main(void) {
	int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
	int size = 3;

	printf("Matrix A:\n");
	print_2D_array(size, A);
	printf("Matrix B:\n");
	print_2D_array(size, B);

	int result[size][size];
	multiply_square_matrix(size, A, B, &result);

	printf("A * B:\n");
	print_2D_array(size, result);
}

void multiply_square_matrix(int n, int A[n][n], int B[n][n], int (*result)[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(*result)[i][j] = 0;
			for (int k = 0; k < n; k++)
				(*result)[i][j] = (*result)[i][j] + A[i][k] * B[k][j];
		}
	}
}

void print_2D_array(int n, int matrix[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}