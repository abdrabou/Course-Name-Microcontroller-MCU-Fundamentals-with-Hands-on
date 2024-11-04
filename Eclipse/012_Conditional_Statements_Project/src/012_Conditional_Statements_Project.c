/*
 ============================================================================
 Name        : 012_Conditional_Statements_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Conditional Statements Project
 ============================================================================
 */

#include <stdio.h>
int main() {
	int num_1 = 10;
	int num_2=-2;
	int num_3 = 0;

	// if statment
	if (num_1 > 0) {
		printf("The number is positive.\n");
	}

	// if-else statment
	if (num_2 > 0) {
		printf("The number is positive.\n");
	} else {
		printf("The number is not positive.\n");
	}

	// if-else if-else statment
	if (num_3 > 0) {
		printf("The number is positive.\n");
	} else if (num_3 < 0) {
		printf("The number is negative.\n");
	} else {
		printf("The number is zero.\n");
	}
	return 0;
}
