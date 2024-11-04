/*
 ============================================================================
 Name        : 010_Function_External_Library_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Function with External Library Project
 ============================================================================
 */

#include <stdio.h>

#include "specialTasks.h"

int main(void) {
	printf("%s\n","Hello, World!");  //This is a predefined, built-in function in C
	task_1();
	task_2();
	specialTask_1();
	task_3();
	specialTask_3();
	return 0;
}
