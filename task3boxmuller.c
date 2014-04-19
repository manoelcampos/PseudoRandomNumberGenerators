/**
 * Program of the Task 3 using Box-Muller Gaussian Pseudo Random Number Generator
 * 
 * @file task3boxmuller.c
 * @author manoelcampos
 * @date March 25, 2014, 8:55 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "lib/commonslib.h"

/**
* Initializes the Box-Muller generator
*/
void boxmuller_init(){
	srand(time(NULL));
}

/**
* Generate a gaussian random number using Box-Muller algorithm
* @return Returns the generated number
*/
double boxmuller(){
    #define RAND() ( rand()/((double) RAND_MAX) )
	static unsigned short cont = 3; 
	static double a, b;
	if(cont > 2){
		a = sqrt(-2 * log(RAND()));
		b = 2 * M_PI * (RAND());
		cont = 1;
	}

	return (cont++ == 1 ? a * sin(b) : a * cos(b));
}


//The amount of pseudo random numbers to be generated
#define SIZE 400

/**
 * Starts the application.
 * @param[in] argc Command line argument count
 * @param[in] argv Command line argument array
 * @return Returns the application exit code
 */
int main(int argc, char** argv) {
	unsigned int i;

	double x=-3; //must be a negative number
	//discover how much integer numbers has in the interval of negative x to positive x
	int int_values = abs(x*2);
	//calculates the increment to start in negative x and go to positive x
	double inc = (double)int_values/(double)SIZE;
	double array[SIZE];
		
	double sum=0, mean, sdev;
	boxmuller_init();
	for(i=0; i < SIZE; i++)
		sum += (array[i] = boxmuller());

	mean = sum / (double)SIZE;
	sdev = stddev(array, mean, SIZE);
	printf("#Box-Muller Gaussian Random Number Generator (GRNG)\n");
	printf("#GaussianRN\tNorm of GRN\tstd value\tStandardNorm\tDiff\n");
	double normX, normx;
	for(i=0; i < SIZE; i++){
		normX = count(array, x, SIZE);
		//normX = cnormdist(array[i], mean, sdev);
		normx = cnormdist(x, 0, 1);
		printf("%lf\t%lf\t%lf\t%lf\t%lf\n", 
			array[i], normX, 
			x, normx, doubleAbs(normX, normx));
		x+=inc;
	}
		
    return (EXIT_SUCCESS);
}


