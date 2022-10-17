#include <stdio.h>

void swap(int *a, int *b);
void bubble_sort(int array[], int size);

int main() {
	int array[10] = {3, 10, 5, 1, 8, 4, 7, 9, 2, 6};
	int size_array = sizeof(array) / sizeof(int);

	for (int i = 0; i < size_array; i++)
		printf("%d ", array[i]);
	printf("\n");

	bubble_sort(array, size_array);

	for (int i = 0; i < size_array; i++)
		printf("%d ", array[i]);
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