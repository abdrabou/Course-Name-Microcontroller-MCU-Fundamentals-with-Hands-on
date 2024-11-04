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
	for (int i = 0; i < 5; i++) {
		printf("Iteration %d\n", i);
		if (i == 3) {
			break; // Exit the loop when i equals 3
		}
	}
	int j = 0;
	while (j < 5) {
		printf("Iteration %d\n", j);
		if (j == 3) {
			break; // Exit the loop when i equals 3
		}
		j++;
	}
	int k = 0;
	do {
		printf("Iteration %d\n", k);
		if (k == 3) {
			break; // Exit the loop when i equals 3
		}
		k++;
	} while (k < 5);
	return 0;
}
