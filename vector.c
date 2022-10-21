/**
 * @file vector.c
 * @author luka luig (luka@4luig.de)
 * @brief small utility array interface
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022 luka luig
 */

#include <stdio.h>
#include <stdlib.h>

// dynamic arrays aka vectors of integers
typedef struct {
	int *vector;
	size_t used;
	size_t size;
} Vector;

// allocates memory for vector
void init_vector(Vector *vec, size_t init_size) {
	vec->vector = malloc(init_size * sizeof(int));
	vec->used = 0;
	vec->size = init_size;
}

// append element, checks for memory
void insert_vector(Vector *vec, int x) {
	// check if enough memory
	// if not -> double size
	if (vec->used == vec->size) {
		vec->size *= 2;
		vec->vector = realloc(vec->vector, vec->size * sizeof(int));
	}
	vec->vector[vec->used++] = x;
}

// remove last element and return it
int pop_vector(Vector *vec) {
	if (vec->used == 0) {
		printf("Vector is already empty");
		return -1;
	} else {
		vec->used--;
		return vec->vector[vec->used];
	}
}

// free allocated memory, remove pointer
void free_vector(Vector *vec) {
	free(vec->vector);
	vec->vector = NULL;
	vec->used = vec->size = 0;
}

void print_vector(Vector *vec) {
	for (int i = 0; i < vec->used; i++)
		printf("%d ", vec->vector[i]);
	printf("\n");
}