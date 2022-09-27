/**
 * @file insertion_sort.c
 * @author luka luig (luka@4luig.de)
 * @brief implementation of clrs algorithm: insertion sort
 * @date 2022-09-27
 *
 * @copyright Copyright (c) 2022 luka luig
 * licensed under the GNU General Public License v3.0
 *
 */

#include <stdio.h>

void print_array(int array[], int size);

int main(void) {
	int array[6] = {12, 6, 43, -7, 3, 14};
	int size_array = sizeof(array) / sizeof(int);
	print_array(array, size_array);

	for (int i = 1; i < size_array; i++) {
		int key = array[i];
		int k = i - 1;
		while (k >= 0 && array[k] > key) {
			array[k + 1] = array[k];
			k--;
		}
		array[k + 1] = key;
	}
	print_array(array, size_array);
}

void print_array(int array[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}
