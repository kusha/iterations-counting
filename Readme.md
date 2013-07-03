Iterations counting
====================================

### Introduction

Counting series functions is intersting problem for IT. Common problem for this algorithm is optimization. This program realise 3 series functions: **power function**, **arctg**, **arsinh**. This functions used in physics, math and some of IT areas.


### Problem analysis

Task: counting infinity series with fixed approximation.
All functions must work with rational numbers.

### Solution draft

#### Helper functions:

##### Square root
![equation](http://latex.codecogs.com/gif.latex?y%3D%5Csqrt%7Bx%7D)

Using Newtone's method.

##### Natural logarithm
![equation](http://latex.codecogs.com/gif.latex?y%3Dlog%28x%29)

![equation](http://latex.codecogs.com/gif.latex?log%28%5Cfrac%7Bx%7D%7Be%7D%29%3Dlog%28x%29-1)

![equation](http://latex.codecogs.com/gif.latex?log%28x*e%29%3Dlog%28x%29%2B1)

![equation](http://latex.codecogs.com/gif.latex?for%5Chspace%7B5pt%7D%7Cx%7C%5Cleq1%3A)

![equation](http://latex.codecogs.com/gif.latex?log%281%2Bx%29%3D%5Csum_%7Bn%3D1%7D%5E%5Cinfty%5Cfrac%7B%28-1%29%5E%7Bn%2B1%7D%7D%7Bn%7D*x%5En%3Dx-%5Cfrac%7Bx%5E2%7D%7B2%7D%2B%5Cfrac%7Bx%5E3%7D%7B3%7D...)

![equation](http://latex.codecogs.com/gif.latex?for%5Chspace%7B5pt%7D%7Cx-1%7C%5Cleq1%5Chspace%7B5pt%7Dunless%5Chspace%7B5pt%7Dx%3D0%3A)

![equation](http://latex.codecogs.com/gif.latex?log%28x%29%3D%28x-1%29-%5Cfrac%7B%28x-1%29%5E2%7D%7B2%7D%2B%5Cfrac%7B%28x-1%29%5E3%7D%7B3%7D-%5Cfrac%7B%28x-1%29%5E4%7D%7B4%7D...)

#### Signification digit

![equation](http://latex.codecogs.com/gif.latex?%5Cepsilon%3D10%5E%7B-%28sigdig%2B1%29%7D)

### Solution

#### Power function
![equation](http://latex.codecogs.com/gif.latex?y%3Da%5Ex)

![equation](http://latex.codecogs.com/gif.latex?x%5Ea%3D1%2B%5Cfrac%7Ba*log%28x%29%7D%7B1%21%7D%2B%5Cfrac%7Ba%5E2*log%5E2%28x%29%7D%7B2%21%7D%2B%5Cfrac%7Ba%5E3*log%5E3%28x%29%7D%7B3%21%7D%2B...%3D%5Csum_%7Bn%3D0%7D%5E%5Cinfty%5Cfrac%7B%28a*log%28x%29%29%5En%7D%7Bn%21%7D)

![equation](http://latex.codecogs.com/gif.latex?Y_%7Bi%2B1%7D%3D%5Cfrac%7BY_%7Bi%7D*a*log%28x%29%7D%7Bi%7D)

![equation](http://latex.codecogs.com/gif.latex?x%5E%7B-a%7D%3D%5Cfrac%7B1%7D%7Bx%5Ea%7D)

![equation](http://latex.codecogs.com/gif.latex?0%5Ea%3D0%5Chspace%7B20pt%7Dfor%5Chspace%7B5pt%7Da%3E0)

![equation](http://latex.codecogs.com/gif.latex?0%5Ea%3D-%5Cinfty%5Chspace%7B20pt%7Dfor%5Chspace%7B5pt%7Da%3C0)

![equation](http://latex.codecogs.com/gif.latex?%28%5Cfrac%7B1%7D%7Bx%7D%29%5Ea%3D%5Cfrac%7B1%7D%7Bx%5Ea%7D%5Chspace%7B20pt%7Dfor%5Chspace%7B5pt%7D0%3Cx%3C1)

#### Arctangent
![equation](http://latex.codecogs.com/gif.latex?y=y%3Darctg%28x%29)

![equation](http://latex.codecogs.com/gif.latex?arctg%28x%29%5Cin%28-%5Cfrac%7B%5Cpi%7D%7B2%7D%3B%5Cfrac%7B%5Cpi%7D%7B2%7D%29)

![equation](http://latex.codecogs.com/gif.latex?arctg%28x%29%3Dx-%5Cfrac%7Bx%5E3%7D%7B3%7D%2B%5Cfrac%7Bx%5E5%7D%7B5%7D-%5Cfrac%7Bx%5E7%7D%7B7%7D%2B...%3D%5Csum_%7Bn%3D0%7D%5E%5Cinfty%28-1%29%5En%5Cfrac%7Bx%5E%7B2n%2B1%7D%7D%7B2n%2B1%7D%5Chspace%7B20pt%7Dfor%5Chspace%7B5pt%7Dx%5Cin%3C-1%3B1%3E)

![equation](http://latex.codecogs.com/gif.latex?arctg%28-x%29%3D-arctg%28x%29)

![equation](http://latex.codecogs.com/gif.latex?arctg%28%5Cfrac%7B1%7D%7Bx%7D%29%3D%5Cfrac%7B%5Cpi%7D%7B2%7D-arctg%28x%29)

![equation](http://latex.codecogs.com/gif.latex?arctg%281%29%3D%5Cfrac%7B%5Cpi%7D%7B4%7D)

#### Hyperbolic arcsine
![equation](http://latex.codecogs.com/gif.latex?y%3Darsinh%28x%29)

![equation](http://latex.codecogs.com/gif.latex?arsinh%28x%29%3Dlog%28x%2B%5Csqrt%7B1%2Bx%5E2%7D%29)

![equation](http://latex.codecogs.com/gif.latex?arsinh%28-x%29%3D-arsinh%28x%29)

### Program

##### Compilation

	gcc -std=c99 -pedantic -Wall -Wextra main.c -o ./iterations
	
or just

	make


#### Usage

print all parameters:

	./iterations --help 

also use this parameters:

	-h				print help
	--help
	--powxa			count exponntial function
	--arctg			count arctangens function
	--argsinh		count argument of sinus hyperbolic function
	[0...]			signification digits
	[real number]	exponetial function parameter
		
example:

	 ./iterations --powxa 7 2.45
	 
program will count exponential function x^2.45 with 7 digits of approximation

**Input is stdin line.**
		

---

#### LICENSE

![CC SA](http://i.creativecommons.org/l/by-sa/3.0/88x31.png)
