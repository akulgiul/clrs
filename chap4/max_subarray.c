/**
 * @file max_subarray.c
 * @author luka luig (luka@4luig.de)
 * @brief implementation of clrs algorithm: find the maximum subarray
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022 luka luig
 * licensed under the GNU General Public License v3.0
 * 
 */

#include <limits.h>
#include <stdio.h>

// simple 3 tuple for 2 indices and a sum
struct tuple3 {
	int low;
	int high;
	int sum;
};

struct tuple3 find_max_crossing_subarray(int array[], int low, int mid, int high);
struct tuple3 find_max_subarray(int array[], int low, int high);
void print_subarray(int array[], int low, int high);

int main(void) {
	int array[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	// int array[2] = {4, 5};
	int size = sizeof(array) / sizeof(int);

	print_subarray(array, 0, size - 1);

	struct tuple3 biggest_subarray = find_max_subarray(array, 0, size - 1);

	printf("biggest subarray: ");
	print_subarray(array, biggest_subarray.low, biggest_subarray.high);
	printf("with sum = %d\n", biggest_subarray.sum);
}

struct tuple3 find_max_crossing_subarray(int array[], int low, int mid, int high) {
	int max_left;  // index of max subarray until mid
	int max_right; // index of max subarray until mid
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;

	for (int i = mid; i >= low; i--) {
		sum += array[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	for (int i = mid + 1; i <= high; i++) {
		sum += array[i];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = i;
		}
	}
	struct tuple3 result = {max_left, max_right, left_sum + right_sum};
	return result;
}

struct tuple3 find_max_subarray(int array[], int low, int high) {
	if (high == low) {
		struct tuple3 base_case = {low, high, array[low]};
		return base_case;
	} else {
		int mid = (low + high) / 2;
		struct tuple3 left = find_max_subarray(array, low, mid);
		struct tuple3 right = find_max_subarray(array, mid + 1, high);
		struct tuple3 cross = find_max_crossing_subarray(array, low, mid, high);

		if (left.sum >= right.sum && left.sum >= cross.sum)
			return left;
		else if (right.sum >= left.sum && right.sum >= cross.sum)
			return right;
		else
			return cross;
	}
}

void print_subarray(int array[], int low, int high) {
	for (int i = low; i <= high; i++)
		printf("%d ", array[i]);
	printf("\n");
}
