/**
 * Program of the Task 1: Tests of LCG PRNG using TestU01
 * 
 * @file task1mylcg_testu01.c
 * @author manoelcampos
 * @date March 25, 2014, 8:55 PM
 */
#include <TestU01.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "lib/lcglib.h"

/**
 * Starts the application.
 * @param[in] argc Command line argument count
 * @param[in] argv Command line argument array. Call the app without parameters to see the usage.
 * @return Returns the application exit code
 */
int main(int argc, char** argv) {
    system("clear");
    printf("Starting the LCG with TestU01\n");
	if(argc==1){
		fprintf(stderr, "usage: %s option\n", argv[0]);
		fprintf(stderr, "\tavailable options:\n");
		fprintf(stderr, "\t\ts - Small Crush TestU01 Test Battery:\n");
		fprintf(stderr, "\t\tc - Crush TestU01 Test Battery:\n");
		fprintf(stderr, "\t\tb - Big Crush TestU01 Test Battery:\n");
		return -1;
	}
	
	char option = argv[1][0];
    //unsigned a=5, b=3, M=16, seed = 10;

    unsigned C, seed;
    unsigned long M; 
    
    lcg_initialize();
    lcg_get_params(&seed, &C, &M);
    printf("C = %u M (period) = %lu seed = %u\n\n", C, M, seed);

    unif01_Gen *gen1 = unif01_CreateExternGenBits("lcg_rand", lcg_rand);
	switch(option){
    	case 's': bbattery_SmallCrush(gen1); break;
    	case 'c': bbattery_Crush(gen1); break;
    	case 'b': bbattery_BigCrush(gen1); break;
		default:
			fprintf(stderr, "Invalid option: %c. Call the application without parameters to see the available options\n", option);		
	}
    unif01_DeleteExternGen01(gen1);

    printf("\n\n");

    return (EXIT_SUCCESS);
}


