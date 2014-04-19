/**
 * Program of the Task 2: Tests of Better LCG PRNG using TestU01
 * 
 * @file task1testu01.c
 * @author manoelcampos
 * @date March 25, 2014, 8:55 PM
 */
#include "TestU01.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "lib/betterlcglib.h"

/**
 * Starts the application.
 * @param[in] argc Command line argument count
 * @param[in] argv Command line argument array. Call the app without parameters to see the usage.
 * @return Returns the application exit code
 */
int main(int argc, char** argv) {
    system("clear");
	if(argc==1){
		fprintf(stderr, "usage: %s option\n", argv[0]);
		fprintf(stderr, "\tavailable options:\n");
		fprintf(stderr, "\t\ts - Small Crush TestU01 Test Battery:\n");
		fprintf(stderr, "\t\tc - Crush TestU01 Test Battery:\n");
		fprintf(stderr, "\t\tb - Big Crush TestU01 Test Battery:\n");
		return -1;
	}
	
	char option = argv[1][0];
    printf("Starting the Better LCG TestU01 with option %c\n", option);
    //unsigned a=5, b=3, M=16, seed = 10;

    unsigned int C[GENERATORS], seed;
    unsigned long M; 
    lcg_initialize();
    lcg_get_params(&seed, C, &M);
    printf("M (period) = %lu seed = %u\nC values:\n", M, seed);
	int i;
	for(i=0; i < GENERATORS; i++)
		printf("%u ", C[i]);
	printf("\n\n");

    unif01_Gen *gen1 = unif01_CreateExternGenBits("better lcg_rand", lcg_rand);
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


