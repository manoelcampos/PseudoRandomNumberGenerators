#include <stdio.h>
#include <stdlib.h>

#include "betterlcglib.h"
#include "commonslib.h"

static unsigned int seed, xn[GENERATORS];
static unsigned long M, module;

//manual and randomically chosen prime numbers
static unsigned int C[GENERATORS] = {
    1607,  61, 1019, 523,  907, 887,  431, 12821, 769, 9173, 223, 7127, 5939, 919, 131, 23,
    911, 5189, 83, 13001,98713, 7229, 967, 1277,  877, 719, 277, 8929, 16033, 733, 3833, 383, 28657
};

void lcg_initialize(){
    seed = 10;
    int i;
    //Initializes all generators with the same seed
    for(i=0; i < GENERATORS; i++)
    	xn[i]=seed;
    
    //All C values needs to be coprime with M
    //C values needs to be coprime wich each others
    
    /*for(i=0; i<GENERATORS; i++) 
    	C[i]=next_prime(381);*/
    
    
    M = 4294967296; //2^32 has 33 bits (only the most significant bit equals 1)
    
    /*Instead of get the module of M, this operation can be faster using
    a logical AND operation. To get the same mod result, 
    the second operand in this AND can be a value with one bit less than
    the  bits amount of M value, but with all bits turned on (all bits equal 1).
    This function call and bit shift operation below do exactly this.*/
    module = bits_turnon(M)>>1; // = 32 bits (all bits equal 1)  
    
    for(i=0; i<GENERATORS; i++)
    	xn[i]=(xn[i] + C[i]) & module; //module = 32 bits (all bits equal 1)      
}

void lcg_get_params(unsigned int *seed_value, unsigned int C_value[], unsigned long *M_value){
    (*seed_value)=seed;
    int i;
    //Manual assignment to avoid external direct change the values of C vector
    for(i=0; i < GENERATORS; i++)
    	C_value[i]=C[i];
    (*M_value)=M;
}

unsigned int lcg_rand(){
    unsigned int lastx, prn = 0;
    int i=GENERATORS-1;
    //Uses right bit shift and AND operation to check what bits of lastx is equals 1
    for(lastx = (xn[i]+=C[i]), i=0; lastx>0; i++, lastx >>= 1)
    	if(lastx & 1)
    		prn ^= (xn[i]+=C[i]);
    
    return prn;
}
