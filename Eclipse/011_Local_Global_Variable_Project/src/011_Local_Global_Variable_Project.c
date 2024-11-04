/*
 ============================================================================
 Name        : 011_Local_Global_Variable_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Local VS Global Variables
 ============================================================================
 */

#include <stdio.h>

int globalVar = 10; // Global variable

void printGlobalVar() {
    printf("Global variable inside function: %d\n", globalVar);
}

void modifyGlobalVar() {
//    int globalVar = 20; // Local variable with the same name as the global variable
        globalVar = 20;   // Update Global variable
    printf("Local variable inside function: %d\n", globalVar);
}

int main() {
    printf("Global variable in main: %d\n", globalVar);

    printGlobalVar(); // Prints the global variable

    modifyGlobalVar(); // Prints the local variable, hiding the global one

    printf("Global variable after function call: %d\n", globalVar);

    return 0;
}
