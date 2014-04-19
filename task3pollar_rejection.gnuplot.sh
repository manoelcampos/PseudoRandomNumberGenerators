#!/usr/bin/gnuplot
#GNU plot script 
#@author Manoel Campos da Silva Filho
 
set macro
filename="/tmp/output.csv"
!bin/task3pollar_rejection > @filename
max=-1
maxdiff(a,b)=(diff=abs(a-b), diff>max?max=diff:max=max, a)

unset label
set table 
plot filename using 1:(maxdiff($2,$4)) 
unset table

set label sprintf("Max Distance: %f", max) at -3,0.96
plot filename using 1:(maxdiff($2,$4)) title "CDF for Pollar Rejection GPRN" smooth cnormal, \
	 filename using 3:4 title "CDF for the Standard Gaussian Distribution" smooth frequency

print "Max diff: ", max

set terminal eps 
set output 'pollar_rejection.eps'
replot