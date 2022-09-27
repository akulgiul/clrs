/**
 * @file merge_sort.c
 * @author luka luig (luka@4luig.de)
 * @brief implementation of clrs algorithm: merge sort
 * @date 2022-09-27
 *
 * @copyright Copyright (c) 2022 luka luig
 * licensed under the GNU General Public License v3.0
 *
 */

#include <limits.h>
#include <stdio.h>

void merge(int array[], int p, int q, int r);
void merge_sort(int array[], int p, int r);
void print_array(int array[], int size);

int main(void) {
	int array[10] = {3, 10, 5, 1, 8, 4, 7, 9, 2, 6};
	int size_array = sizeof(array) / sizeof(int);
	printf("Initial array: ");
	print_array(array, size_array);

	merge_sort(array, 0, size_array - 1);
	printf("Sorted: ");
	print_array(array, size_array);
}

void merge(int array[], int p, int q, int r) {
	// lengths of subbarrays
	int n1 = q - p + 1;
	int n2 = r - q;

	// filling L with first subarray
	int L[n1 + 1];
	for (int i = 0; i < n1; i++)
		L[i] = array[p + i];
	L[n1] = INT_MAX; // sentinel

	// filling R with second subarray
	int R[n2 + 1];
	for (int i = 0; i < n2; i++)
		R[i] = array[q + 1 + i];
	R[n2] = INT_MAX; // sentinel

	// from L and R: compare and copy into array
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		} else {
			array[k] = R[j];
			j++;
		}
	}
}

void merge_sort(int array[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(array, p, q);
		merge_sort(array, q + 1, r);
		merge(array, p, q, r);
	}
}

void print_array(int array[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}