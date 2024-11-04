/*
 ============================================================================
 Name        : 015_Pointer_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer Project
 ============================================================================
 */

#include <stdio.h>

int main() {
    // Declaration of a variable and a pointer
    int size = 15;        // 'size' is a regular integer variable
    int *pointerInt;      // 'pointerInt' is a pointer variable that can hold the address of an integer

    // Assign the address of the variable 'size' to the pointer 'pointerInt'
    pointerInt = &size;

    // Output the value of 'size' and its memory address
    printf("Value of size: %d\n", size);   //Output: 15
    printf("Address of size: %p\n", &size);//Output: Address of 'size'

    // Output the value stored in 'pointerInt' and the value it points to
    printf("Value of pointerInt (address of size): %p\n", pointerInt);  // Output: Same as &size
    printf("Value pointed to by pointerInt: %d\n", *pointerInt);        // Output: 15

    // Modify the value of 'size' through the pointer
    *pointerInt = 25;
    printf("New value of size after modification through pointer: %d\n", size);  // Output: 25

    return 0;
}
