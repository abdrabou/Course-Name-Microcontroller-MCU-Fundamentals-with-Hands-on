/*
 ============================================================================
 Name        : 003_Code_Modularity_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Preprocessor, this example illustrate  #undef and #pragma once
 ============================================================================
 */

#include <stdio.h>

#include "specialTasks.h"

//Function prototypes
void task_1(void);
void task_2(void);
void task_3(void);

int main(void) {
	printf("%s\n","Hello, World!");  //This is a predefined, built-in function in C
	task_1();
	task_2();
	specialTask_1();
	task_3();
	specialTask_3();
	return 0;
}

void task_1(void){
	specialTask_1();
}

void task_2(void){
	specialTask_4();
}

void task_3(void){
	printf("%s\n","task_3 was called");
	printf("We still in task3 type anything to continue  ");
	fflush(stdout);
	int num;
	scanf("%d", &num);
//	getchar();
}
