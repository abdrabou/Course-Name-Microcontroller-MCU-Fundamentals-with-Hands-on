/*
 ============================================================================
 Name        : 004_Variable_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Variable
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//An alternative is to manually define a new type:
typedef int Bool;      // Create a new type name `Bool` for `int` it could be any other thing
#define True 1
#define False 0

int main(void) {
	float discount = 0.5;
	int age = 998;
	char a = 'N';

	printf("discount: %f\n",discount);
	printf("y: %d\n",age);
	printf("a: %c\n",a);

    printf("float size: %lu bytes\n", (unsigned long)sizeof(discount));
    printf("int size: %lu bytes\n", (unsigned long)sizeof(age));
    printf("short size: %lu bytes\n", (unsigned long)sizeof(a));

	Bool aBooleanVariable;           // Declare a variable of type `Bool` (which is an `int`)
									 // Bool is an alias for int. This means that anywhere in your code where you use Bool, it is treated as if you are using int.
	aBooleanVariable = True;         // Assign the value `1` to the variable
	printf("The value of aBooleanVariable is %d\n",aBooleanVariable);

    return 0;
}

