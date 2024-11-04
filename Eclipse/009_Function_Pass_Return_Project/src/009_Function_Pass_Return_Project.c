/*
 ============================================================================
 Name        : 009_Function_Pass_Return_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Function Pass & Return
 ============================================================================
 */

#include <stdio.h>

//Function prototypes
void function1();
void function2(int a, int b);
int  function3(int a, int b);

int main() {

	function1(); //Call function without pass any arguments
	function2(5,6); // Pass arguments to the function
	int result = function3(6, 7);//Pass argument & store return value
	printf("The product is: %d, printed inside main \n", result);

	return 0;
}

//Function Definition
void function1() {
	printf("Hello, World!\n");
}
void function2(int a, int b) {
	int sum = a + b;
	printf("The sum is: %d, printed inside function2 \n", sum);
}
int function3(int a, int b) {
	return a * b;
}
