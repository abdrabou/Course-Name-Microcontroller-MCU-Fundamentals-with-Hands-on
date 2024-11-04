/*
 ============================================================================
 Name        : 006_Arithmetic_Operators_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Arithmetic Operation
 ============================================================================
 */

#include <stdio.h>

int main() {

	int a = 15, b = 4, add_assign = 10, sub_assign = 100, mul_assign = 5,div_assign = 30,mod_assign = 49;
	//Basic Operators
	int sum = a + b;             //addition
	int difference = a - b;      //subtraction
	int product = a * b;         //multiplication
	int quotient = a / b;        //divition
	int remainder = a % b;       //Modulus
	//Unary Operators
	int increment =a++;          //increment by 1
	int decrement =a--;          //decrement by 1
	//Compound Assignment Operators: +=, -=, *=, /=, %=
	add_assign += 10;            //add and assign
	sub_assign -= 50;			 //subtract and assign
	mul_assign *=7;              //multiply and assign
	div_assign /=6;              //divide and assign
	mod_assign *=8;              //mod and assign
	printf("Result of a + b = %d\n", quotient);
	return 0;

}

