/**
 * @file bubble_sort.c
 * @author luka luig (luka@4luig.de)
 * @brief implementation of clrs algorithm: bubble sort
 * @date 2022-09-27
 *
 * @copyright Copyright (c) 2022 luka luig
 * licensed under the GNU General Public License v3.0
 *
 */

#include <stdio.h>

void bubble_sort(int array[], int size);
void swap(int *a, int *b);
void print_array(int array[], int size);

int main() {
	int array[10] = {3, 10, 5, 1, 8, 4, 7, 9, 2, 6};
	int size_array = sizeof(array) / sizeof(int);
	print_array(array, size_array);

	bubble_sort(array, size_array);
	print_array(array, size_array);
}

void bubble_sort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--) {
			if (array[j] < array[j - 1])
				swap(&array[j], &array[j - 1]);
		}
	}
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_array(int array[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}