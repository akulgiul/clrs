/**
 * @file helper.c
 * @author luka luig (luka@4luig.de)
 * @brief small utility "class" for regular used functions
 * @date 2022-10-19
 *
 * Copyright (c) 2022 luka luig
 *
 */

#include <stdio.h>

// user input for int in given range (including min and max)
int input_int_min_max(int min, int max, char attribute[]) {
	int input = min - 1;
	while (1) {
		printf("%s\nPlease enter an integer from %d to %d: ", attribute, min, max);
		scanf("%d", &input);
		if (input >= min && input <= max)
			return input;
		else
			printf("Sorry! Integer entered is not in range.\n");
	}
}