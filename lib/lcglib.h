/**
 * Implements a Linear Congruential Generators (LCG)
 * for pseudo random numbers.
 * This library is used by task 1.
 * 
 * @file   lcglib.h
 * @author manoelcampos
 * @date March 26, 2014, 12:38 AM
 */

#ifndef LCG_H
#define	LCG_H


/**
 * Initializes the RNG with the default values.
 * @param iseed The first value of the sequence (the seed)
 * @see lcg_get_params
 */
void lcg_initialize(int iseed);

/**
* Gets the internal parameters used by the generator.
* @param[out] seed_value The value of the seed
* @param[out] C_value The value of C parameter
* @param[out] M_value The value of M period 
* @see lcg_initialize
*/
void lcg_get_params(unsigned int *seed_value, unsigned int *C_value, unsigned long *M_value);


/**
* Gets the next generated pseudo random number.
* @see lcg_initialize
*/
unsigned int lcg_rand();

#endif	/* LCG_H */

