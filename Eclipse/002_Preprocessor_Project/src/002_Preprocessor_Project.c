/*
 ============================================================================
 Name        : 002_Preprocessor_Project.c
 Author      : Mohammed Hammouda
 Version     :
 Copyright   : Your copyright notice
 Description : Preprocessor, this example illustrate  #undef and #pragma once
 ============================================================================
 */

#include <stdio.h>
#include "myheader.h" //First inclusion of header file
#include "myheader.h" //Second inclusion of same header file

#define debug

//#undef debug

#ifdef debug
#define LOG(msg) printf("DEBUG: %s\n", msg)
#else
#define LOG(msg)
#endif

int main() {
	LOG("Starting the program");
	myFunction(); // Calling the function from the header file
	printf("Hello, World!\n");
	LOG("Ending the program");
	return 0;
}
