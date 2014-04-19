/**
 * Program of the Task 2: Implementing a better LCG for PRNG
 * 
 * @file task2.c
 * @author manoelcampos
 * @date April 2, 2014, 8:55 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/betterlcglib.h"
#include "lib/commonslib.h"

/**
 * Starts the application.
 * @param[in] argc Command line argument count
 * @param[in] argv Command line argument array
 * @return Returns the application exit code
 */
int main(int argc, char** argv) {
    printf("Starting the Better LCG without TestU01\n");
    //unsigned a=5, b=3, M=16, seed = 10;

    unsigned int C[GENERATORS], seed;
    unsigned long M; //4294967296 = 2^32

    unsigned long long i;
    
    lcg_initialize();
    lcg_get_params(&seed, C, &M);
    unsigned long long numbers_count= 40;
    printf("M (period) = %lu seed = %u numbers: %llu\n\n", M, seed,numbers_count);
    puts("C values:");
    for(i=0; i < GENERATORS; i++)
    	printf("%u ", C[i]);
	puts("\n");
    //período: 4294967296 (exatamente o M inicial)
    printf("My lcg_rand()\n");
    unsigned int r;
    for(i=1; i <= numbers_count; i++){
     	r = lcg_rand();
        printf("%u ", r);
    }
    printf("\n\nsaiu do laço sem encontrar o período: %llu\n\n", i);
    printf("\n\n");

    return (EXIT_SUCCESS);
}

