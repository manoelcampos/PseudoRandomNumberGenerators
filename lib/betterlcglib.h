/**
 * Implements a better Linear Congruential Generators (LCG)
 * for pseudo random numbers.
 * This library is used by task 1.
 * 
 * @file   betterlcglib.h
 * @author manoelcampos
 * @date April 2, 2014, 12:38 AM
 */

#ifndef LCG_H
#define	LCG_H

#define GENERATORS 33

/**
 * Initializes the RNG with the default values.
 * @see lcg_get_params
 */
void lcg_initialize();

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

