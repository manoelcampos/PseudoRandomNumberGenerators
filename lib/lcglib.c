#include <stdio.h>
#include <stdlib.h>

#include "lcglib.h"
#include "commonslib.h"

static unsigned int seed, xn, C;
static unsigned long M, module;

void lcg_initialize(int iseed){
    seed = iseed;
    xn = seed;
    
    //C and M need to be coprime
    C=12345;
    M = 4294967296; //2^32 has 33 bits (only one bit equal 1)
    module = bits_turnon(M)>>1; // = 32 bits (all bits equal 1)  
    
    if(gcd(C, M)!=1){
        fprintf(stderr, "Error in lcg_initialize: M (%lu) and C (%u) must be coprime\n", M, C);
        exit(-1);
    }
}

void lcg_get_params(unsigned int *seed_value, unsigned int *C_value, unsigned long *M_value){
    (*seed_value)=seed;
    (*C_value)=C;
    (*M_value)=M;
}

unsigned int lcg_rand(){
    unsigned int res = xn;
    //the module is very, very slow
    //xn=(xn + C) % M;
    
    //10111b / 8 (2^3) = 10111b / 2 / 2 / 2 = 10111>>3 = 10b (size-3 first bits) * 8 = 10000
    //1000101001b % 2^5 == last 5 bits
    //1000101001b / 2^5 == first 5 bits
    //faster than using (xn + C) % M
    xn=(xn + C) & module; // = 32 bits (all bits equal 1)  
    return res;
}
