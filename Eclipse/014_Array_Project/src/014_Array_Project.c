/*
 ============================================================================
 Name        : 014_Array_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Array Project
 ============================================================================
 */

#include <stdio.h>

int main() {
	// Declaration and initialization of a one-dimensional array
	int numbers[5] = {10, 20, 30, 40, 50};
	// Declaration and initialization of a two-dimensional array
	int matrix[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
		 };
	// Accessing specific indices
	printf("Element at index 0: %d\n", numbers[0]); // Output: 10
    printf("Element at [1][2]: %d\n", matrix[1][2]); // Output: 7

	// Modifying an element
	numbers[4] = 100;
	matrix[0][3] = 99;
	printf("Element at index 4 after modification: %d\n", numbers[4]); // Output: 100
    printf("Element at [0][3] after modification: %d\n", matrix[0][3]); // Output: 99
	return 0;
}
