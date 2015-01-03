/**
 * Program of the Task 1: Generation of Pseudo Random Numbers using LCG
 * 
 * @file task1mylcg.c
 * @author manoelcampos
 * @date March 25, 2014, 8:55 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/lcglib.h"

/**
 * Starts the application.
 * @param[in] argc Command line argument count
 * @param[in] argv Command line argument array
 * @return Returns the application exit code
 */
int main(int argc, char** argv) {
    printf("Starting the LCG without TestU01\n");
    //unsigned a=5, b=3, M=16, seed = 10;

    unsigned int C, seed;
    unsigned long M;

    /* Total de números a serem gerados.
     * Foi usado múltiplo de M apenas para mostrar que a sequência
     * realmente repete depois de M iterações
     * */
    unsigned long numbers_count=10;
    
    lcg_initialize(10);
    lcg_get_params(&seed, &C, &M);
    printf("C = %u M (period) = %lu seed = %u\n\n", C, M, seed);
    
    unsigned long i;
    printf("My lcg_rand()\n");
    for(i=1; i <= numbers_count; i++){
        printf("%u ", lcg_rand());
        if(i % M == 0)
            printf("| \n");
    }
    printf("\n\n");

    return (EXIT_SUCCESS);
}

