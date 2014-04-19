#include "commonslib.h"
#include <math.h>

unsigned long gcd(unsigned long a, unsigned long b){
  if(a==0) 
      return b;
  
  return gcd(b%a, a);
}

unsigned long bits_turnon(unsigned long num){
  unsigned long x, i=1;
  for(x=num; x; i<<=1, x>>=1)
     num |= i;

  return num;
}

short is_prime(unsigned int num){
	unsigned int i;
	if(num==1)
		return 0;
		
	for(i=2; i < num; i++)
		if(num % i == 0)
			return 0;
			
	return 1;
}

unsigned int next_prime(unsigned int start){
	int i=start+1;
	while(!is_prime(i))
		i++;
		
	return i;
}

double normdist(double x, double mean, double stdev){
	double p = pow((x-mean)/stdev,2);
	return (1.0/(stdev*sqrt(2.0*M_PI))) * exp(-0.5*p);	
}

double cnormdist(double x, double mean, double stdev){
	return 0.5 + 0.5*erf((x-mean)/stdev/1.4142135623731);
	
	//double p = (x-mean)/sqrt(2*stdev*stdev);
	//return (0.5 * (1+erf(p)));	
}

double stddev(double values[], double mean, int size){
	int i;
	double sum = 0;
	for(i=0; i < size; i++)
		sum += pow(values[i]-mean, 2);
	return sqrt(sum/(double)size);
}

double doubleAbs(double a, double b){
	if(a > b)
		return a-b;
	return b-a;
}

double count(double values[], double x, int size){
	int i;
	double c = 0;
	for(i=0; i < size; i++)
		c += (values[i]<x);
			
	return c/(double)size;	
}