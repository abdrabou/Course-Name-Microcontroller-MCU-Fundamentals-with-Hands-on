/*
 ============================================================================
 Name        : 007_Logical_Operator_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Logical Operator
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int x = 5;
	int y = 7;

	printf("(x == y) is %d\n",(x==y)); //== is-equal?
	printf("(x != y) is %d\n",(x!=y)); //!= is-not-equal?
	printf("(x  > y) is %d\n",(x>y));  //>  bigger than?
	printf("(x  < y) is %d\n",(x<y));  //<  smaller than?
	printf("(x >= y) is %d\n",(x>=y)); //>= bigger-or-equal than?
	printf("(x <= y) is %d\n",(x<=y)); //<= smaller-or-equal than?

    int max = (x > y) ? x : y; //ternary operator: Assigns the larger of x and y to max
    printf("The maximum value is %d\n", max);

	x = 1;
	y = 0;
	printf("(x && y) is %d\n",(x && y));   //&& logical and
	printf("(x || y) is %d\n",(x || y));   //|| logical or
	printf("   !x    is %d\n",!x);         //!  not

	return 0;
}

