#include <stdio.h>

void specialTask_1(void){
	printf("%s\n","specialTask_1 was called");
}

void specialTask_2(void){
	printf("%s\n","specialTask_2 was called");
}

void specialTask_3(void){
	printf("%s\n","specialTask_3 was called");
}

void specialTask_4(void){
	printf("%s\n","specialTask_4 was called");
}

void task_1(void){
	specialTask_1();
}

void task_2(void){
	specialTask_4();
}

void task_3(void){
	printf("%s\n","task_3 was called");
	printf("We still in task3 enter your age: ");
	fflush(stdout);
	int num;
	scanf("%d", &num);
	printf("Your age: %d\n", num);
//	getchar();
}
