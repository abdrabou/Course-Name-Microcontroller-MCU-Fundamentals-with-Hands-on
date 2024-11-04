/*
 ============================================================================
 Name        : 017_System_Tool_Debug_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : System Tool Debug Project
 ============================================================================
 */

#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += a + b;
        printf("Iteration %d: sum = %d\n", i + 1, sum);
    }
    return 0;
}
