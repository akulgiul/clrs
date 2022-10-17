#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
	int array[6] = {12, 6, 43, -7, 3, 14};
	int size_array = sizeof(array) / sizeof(int);

	for (int i = 1; i < size_array; i++) {
		int key = array[i];
		int k = i - 1;
		while (k >= 0 && array[k] > key) {
			array[k + 1] = array[k];
			k--;
		}
		array[k + 1] = key;
	}

	for (int i = 0; i < size_array; i++) {
		printf("%d, ", array[i]);
	}
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}