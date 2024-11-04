/*
 ============================================================================
 Name        : 016_Manual_Debug_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Manual Debug Project
 ============================================================================
 */

#include <stdio.h>

//Constants
#define DEBUG_ON  1
#define DEBUG_OFF 0
#define DEBUG_ALERT "----->"

// Globals
int debugFlag = DEBUG_ON;

void Function1(int,int);
void Function2(float,float);

int main(void) {
	Function1(3,5);
	Function2(2.0,3.0);

	return 0;
}

void Function1(int a, int b){
	if(debugFlag)
		printf ("%s In Function1, received a=%d, b=%d\n",DEBUG_ALERT, a,b);

	printf("    Function1 is executing...\n");
	printf("    Function1 is still doing something...\n");
	printf("    Function1 keeps going...\n");

	//Rest of function code
}

void Function2(float a, float b){
	if(debugFlag)
		printf ("%s In Function2, received a=%f, b=%f\n",DEBUG_ALERT,a,b);

	printf("    Function2 is executing...\n");
	int k = 4; int j = 8; int z = -4;
	double m = (double)k * (double)k /((double) j + (double) z);
	if(debugFlag)
		printf ("%s In Function2, m=%lf at line %d\n",DEBUG_ALERT,m,__LINE__);

	//Rest of function code
}
