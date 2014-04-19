/**
 * Program of the Task 3 using Pollar Rejection Gaussian Pseudo Random Number Generator
 * 
 * @file task3pollar_rejection.c
 * @author manoelcampos
 * @date March 25, 2014, 8:55 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "lib/commonslib.h"

/**
* Initializes the Pollar Rejection generator
*/
void pollar_rejection_init(){
	srand(time(NULL));
}

/**
* Generate a gaussian random number using Pollar Rejection algorithm
* @return Returns the generated number
*/
double pollar_rejection(){
	#define RAND() (2*(rand()/(1.0*RAND_MAX))-1)
	static unsigned short cont = 3; 
	static double v1, v2, d, f;

	if(cont > 2){
		do {
			v1 = RAND();  v2 = RAND();
			d = v1*v1 + v2*v2;
		} while(d <= 0 || d >= 1);
		cont = 0;
		f = sqrt(-2 * log(d)/d);
	}

	return (++cont == 1 ? f*v1 : f*v2 );
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
	pollar_rejection_init();
	for(i=0; i < SIZE; i++)
		sum += (array[i] = pollar_rejection());

	mean = sum / (double)SIZE;
	sdev = stddev(array, mean, SIZE);
	printf("#Pollar Rejection Gaussian Random Number Generator (GRNG)\n");
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