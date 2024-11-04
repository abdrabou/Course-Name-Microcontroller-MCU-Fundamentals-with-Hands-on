/*
 ============================================================================
 Name        : 008_Bit_Level_Operator_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Bit Level Operator with bitwise operation
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int a = 12; // Binary: 00001100
    int b = 7;  // Binary: 00000111
    int c = 5;  // Binary: 00000101
	int d = 20; // Binary: 00010100

    int result_and = a & b; // Binary: 00000100 (Decimal: 4)
    int result_or  = a | b; // Binary: 00001111 (Decimal: 15)
    int result_xor = a ^ b; // Binary: 00001011 (Decimal: 11)
    int result_not = ~a;    // Binary: 11110011 (Decimal: -13 for a 8-bit signed integer)
    int result_shift_left  = c << 2; // Binary: 00010100 (Decimal: 20)
    int result_shift_right = d >> 2; // Binary: 00000101 (Decimal: 5)

    printf("Result %d\n",result_xor);
	printf("Result %u\n",result_not);   //format specifier %d %u
	return 0;
}

