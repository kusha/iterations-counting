/*                 
 * File:  main.c
 * Date:   3.11.2012
 * Author:   Mark Birger, birger.mark@gmail.com
 * Project: IZP c. 2 - Counting iterations
 * Text editor: Sublime Text 2
 * Compiled with gcc 4.2.1
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const double IZP_E = 2.7182818284590452354;        // e becuase of this constant max input data 20 numbers
const double IZP_PI = 3.14159265358979323846;      // pi
const double IZP_2PI = 6.28318530717958647692;     // 2*pi
const double IZP_PI_2 = 1.57079632679489661923;    // pi/2
const double IZP_PI_4 = 0.78539816339744830962;    // pi/4

//DEFINE CONSTANTS
//const with help infromation 
const char *HELPMSG =  
"Program: \"Iteration counting\".\n"
"Author: Mark Birger.\n"
"Counting some functions series.\n"
"Usage:	./iterations --help\n"
"		print all parameters\n"
"Use this parameters:\n"
"		-h				print help\n"
"		--help\n"
"		--powxa			count exponntial function\n"
"		--arctg			count arctangens function\n"
"		--argsinh		count argument of sinus hyperbolic function\n"
"		[0...]			signification digits\n"
"		real number]	exponetial function parameter\n"
"Example: ./iterations --powxa 7 2.45\n"
"		program will count exponential function x^2.45\n"
"		with 7 digits of approximation\n";

char *HELP0="-h";
char *HELP1="--help";
char *ARG_POW="--powxa";
char *ARG_ARCTG="--arctg";
char *ARG_ARSINH="--argsinh";

const char*ERRMSG0 = "Cant recognize command. Try to use help.\n";
const char*ERRMSG1 = "Cant recognize signification digits. Try to use help.\n";
const char*ERRMSG2 = "Below zero signification digits.\n";
const char*ERRMSG3 = "There is no a.\n";

//PRINT HELP FUNCTION
int print_help() {
	printf("%s", HELPMSG);
	return 1;
}

//SQRT  FUNCTION via NEWTON'S METHOD
double sqr (double x, double eps) {

	//RANGE ERROR CHECKING
	if (x<0) { 
		return 0.0/0.0;
	}
	else if (x==0) {
		return 0;
	}

	//Newtone's method have problems with extremly small numbers
	double c = 1;
	if (x<1) {
		c = x;
		x = 1/x;
	}

	//ROOT COUNTING
	double aprx=1;
	double previous=0;
	double q;
	do {
		q = x/aprx;
		previous = aprx;
		aprx=(q+aprx)/2;
		//printf("%.30f : %.30f\n", previous, aprx);
	} while (fabs(previous-aprx)>eps);
	return c*aprx;
}

//COUNTING NATURAL LOGARITHM USING TAYLOR SERIES
double ln (double x, double eps) { 

	// RANGE ERROR CHECKING
	if (x<0) { 
		return 0.0/0.0;
	}
	else if (x==0) {
		return -1.0/0.0;
	}
	else if (x==1) { //loophole for divide by zero in this function
		return 0.0;
	}

	// INPUT DATA OPTIMIZATION
	int div_c=0; //divide counter
	int mul_c=0; //multiply counter
	if (x>=1) {
		// OPTIMIZATION via DIVIDE
		while (x>=1) {
			x = x / IZP_E;
			++div_c;
		} 
	} else {
		//// OPTIMIZATION via MULTIPLY
		while ((x * IZP_E)<1) {
			x = x * IZP_E;
			++mul_c;
		} 
	}

	// COUNTING LOGARITHM
	--x; //function specific, more in documentation 
	double sum = 0;
	double previous = 0;	
	double next = x;
	double xpow = x; // counting power function
	int i = 2;
	do {
		sum = sum + next;
		previous = next;
		xpow = xpow * x * -1; // minus and power will count together
		next = xpow/i;
		++i;
	} while (fabs(previous-next)>eps);

	// ACCEPT OPTIMIZATION
	if (div_c) {sum += div_c;} //by divide
	if (mul_c) {sum -= mul_c;} //by multiply

	//RETURN
	return sum;
}


//POWER FUNCTION
double pwr (double x, double a, double eps) {

	// RANGE ERROR CHECKING

	if (x<0) { 
		return 0.0/0.0;
	}

	_Bool bz_power = 0; //below zero power
	if ((a < 0)&&(x != 0)) {bz_power = 1; a = -a;}

	if ((x==0)&&(a>0)) {
		return 0;
	}

	_Bool xo_power = 0; //x less than 1
	if ((x<1)&&(x>0)) {
		xo_power = 1;
		x = 1/x;
	}

	eps = eps/100; // special more accuracy

	double sum = 0;
	double previous = 0;	
	double next = 1;
	double logarithm = ln (x,eps);
	int i = 1;
	do {
		sum = sum + next;
		previous = next;
		next = previous * logarithm * a / i;
		//printf("%d : %.25f : %.25f : %.25f\n", i, sum ,previous, next);
		++i;
	} while (fabs(next-previous)>eps);

	if (xo_power) {
		sum = 1/sum;
	} 

	if (bz_power) {
		sum = 1/sum;
	} 

	return sum;
}

//ARCTG FUNCTION via TAYLOR SERIES
double arctg (double x, double eps) {

	double c=1;
	if(x<0){
		x = -x;
		c= -1;
	}

	// ARGUMENT X OPTIMIZATION

	if (x==1) {return IZP_PI_4;}

	_Bool Pi_flag = 0; 
	if (x>1) {x = 1/x; Pi_flag =1;}

	//ARCTAN COUNTING

	double sum = 0;
	double previous = 0;	
	double next = x;
	double xpow = x;
	double x2 = x*x;
	int i = 3;
	do {
		sum = sum + next;
		previous = next;
		xpow = xpow * x2 * -1; // minus and power counted together
		next = xpow/i;
		//printf("%2d : %.20f : %.20f : %.20f : %.20f\n", i, sum, previous, next, (previous-next));
		i += 2;
	} while (fabs(next-previous)>=eps);

	if (Pi_flag) {
		sum = (IZP_PI_2 - sum);
	} 

	return c*sum;
}



//ARSINH FUNCTION
double ash (double x, double eps) {
	double c = 1; //coefficient
	if (x<0) { c=-1.0; x=-x; } //range correction
	return c* ln(x+sqr(1+x*x,eps),eps);
}

// ACCURACY DETECTION
double accuracy (int sigdig) {
	double acc = 1; //accuracy
	int i;
	for (i=0; i<=sigdig; ++i) {
		acc = acc/10; // accuracy is sd+1 after the point
	}
	return acc;
}

int main(int argc, char *argv[])
{
	//flags:
	_Bool arg_pow = 0;
	_Bool arg_arctg = 0;
	_Bool arg_arsinh = 0;

	int sd = -1; //signification digits
	double a; //power function argument
	_Bool a_flag = 0;

	argc = argc; //for not warning message

	//find arguments in argv[]
	int i=1;
	//first of all try to recognize help argument
	if (!argv[i]) {
		fprintf(stderr, "%s", ERRMSG0); //command hasn't recognized
		return 1;
	}
	if (!strcmp(argv[i], HELP0) || !strcmp(argv[i], HELP1)) {
		if (print_help()) {
			return 0;
		}
	} else if (!strcmp(argv[i], ARG_POW)) {
		arg_pow = 1;
	} else if (!strcmp(argv[i], ARG_ARCTG)) {
		arg_arctg = 1;
	} else if (!strcmp(argv[i], ARG_ARSINH)) {
		arg_arsinh = 1;
	} else {
		fprintf(stderr, "%s", ERRMSG0); //command hasn't recognized
		return 1;
	}

	if (argv[i+1]) {sd = atoi(argv[i+1]);}
	if(sd<0) {
		fprintf(stderr, "%s", ERRMSG2); //command hasn't recognized
		return 1;
	}

	if ((arg_pow)&&(argv[i+2])) {
		a = strtod (argv[i+2], NULL);
		a_flag = 1;
	}
	if ((arg_pow)&&(!a_flag)) {
		fprintf(stderr, "%s", ERRMSG3); //there is no a
		return 1;
	}

	double eps = accuracy (sd);

	int temp;
	double x;
	while ((temp = scanf("%lf", &x)) != EOF)
	{
	    if (temp == 0) {
	    	scanf("%*s");
	    	printf("%f\n", 0.0/0.0); //there is no float point number
	    } else if (arg_pow) {
	    	printf("%.10e\n", pwr(x,a,eps));
	    } else if (arg_arctg) {
	    	printf("%.10e\n", arctg(x,eps));
	    } else if (arg_arsinh) {
	    	printf("%.10e\n", ash(x,eps));
	    }
	}

	//FINISH
}
