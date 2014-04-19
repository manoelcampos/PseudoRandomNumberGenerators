/**
 * Commons useful general purpose functions used by all tasks.
 * 
 * @file   commonslib.h
 * @author manoelcampos
 * @date March 26, 2014, 12:38 AM
 */

#ifndef COMMONS_H
#define	COMMONS_H

/**
 * Turn on all the bits of a number (setting each bit to 1)
 * @param num The number to have all the bits tunned on.
 * @return Return the new number with all bits equals to 1
 */
unsigned long bits_turnon(unsigned long num);

/**
 * Greater Common Divisor.
 * @param a 
 * @param b
 * @return Retuns the greater common divisor of the two numbers.
 */
unsigned long gcd(unsigned long a, unsigned long b);

/**
 * Checks if a number is prime or not.
 * @param num The number to be checked. 
 * @return Retuns true (1) se the number is prime or false (0) otherwise.
 */
short is_prime(unsigned int num);

/**
 * Gets the next prime number after the informed value.
 * @param start The number after what will be returned the next prime number.
 * This can be any number.
 * @return Retuns the next discovered prime number after the start value.
 */
unsigned int next_prime(unsigned int start);


/**
* Calculates the normal distribution of a giver number
* @param x The desired number to generate the normal distribution
* @param mean The mean of the desired distribution
* @param stdev The standard deviation of the desired distribution
*/
double normdist(double x, double mean, double stdev);

/**
* Calculates the CDF of normal distribution of a giver number
* @param x The desired number to generate the normal distribution
* @param mean The mean of the desired distribution
* @param stdev The standard deviation of the desired distribution
*/
double cnormdist(double x, double mean, double stdev);
/**
* Calculates the standard deviation of a set
* @param values The set to calculate the standard deviation
* @param mean The mean of the set values
* @param stdev The set size
*/
double stddev(double values[], double mean, int size);

/**
* Calculates the absolute value from the difference of two double numbers
* @param a The first value
* @param b The second value
* @return Returns the absolute difference of the numbers.
*/
double doubleAbs(double a, double b);

/**
* Calculates the CDF of a normal distribution from a value
* of the standard normal distribution
* @param values The values of the normal distribution 
* to be calculates the CDF
* @param x The value of the standard normal distribution
* @param size The size of the values vector
* @return Returns the calculated CDF
*/
double count(double values[], double x, int size);

#endif	/* COMMONS_H */