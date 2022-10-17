// #include <math.h>
#include <stdio.h>

void merge(int array[], int p, int q, int r);
void merge_sort(int array[], int p, int r);
void print_array(int array[], int size);

int main(void) {
	int array[10] = {3, 10, 5, 1, 8, 4, 7, 9, 2, 6};
	int size_array = sizeof(array) / sizeof(int);

	for (int i = 0; i < size_array; i++)
		printf("%d ", array[i]);
	printf("\n");

	merge_sort(array, 0, size_array - 1);

	for (int i = 0; i < size_array; i++)
		printf("%d ", array[i]);
}

void merge(int array[], int p, int q, int r) {
	// lengths of subbarrays
	int n1 = q - p + 1;
	int n2 = r - q;

	// filling L with first subarray
	int L[n1];
	for (int i = 0; i < n1; i++)
		L[i] = array[p + i];

	// filling R with second subarray
	int R[n2];
	for (int i = 0; i < n2; i++)
		R[i] = array[q + 1 + i];

	// from L and R: compare and copy into array
	int i = 0;
	int j = 0;
	int k = p;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
			k++;
		} else {
			array[k] = R[j];
			j++;
			k++;
		}
	}
	// remainder
	while (i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		array[k] = R[j];
		j++;
		k++;
	}

	// // WHY THE FUCK DOES THIS NOT WORK???????
	// for (int k = p; k <= r; k++) {
	// 	if (i < n1 && L[i] <= R[j]) {
	// 		array[k] = L[i];
	// 		i++;
	// 	} else {
	// 		array[k] = R[j];
	// 		j++;
	// 	}
	// }
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
}