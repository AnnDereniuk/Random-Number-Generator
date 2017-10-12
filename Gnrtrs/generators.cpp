#include <iostream>
#include "generators.h"
#define e 2.71828
#define pi 3.14159
using namespace std;

unsigned int a1 = 3;
unsigned int m1 = 107;
unsigned int c1 = 147;

unsigned int m2 = 322701;
unsigned int d = 1680;

const int a2 = 14;
const int c2 = 12346;
const int p = 571;

const int median = 0;
const int sigma = 1;

const int mu = 150;
const int a3 = 15;

double linearCongruent(unsigned int x_1) {
	x_1 = (a1*x_1 + c1) % m1;
	return (double)x_1;
}


double quadraticCongruent(unsigned int x_2) {
	x_2 = (x_2*x_2*d + x_2*a1 + c1) % m2;
	return (double)x_2;
}

double fibonacciNumbers(unsigned int x_3) {//???
	unsigned int x_31 = x_3+2;

	x_3 = (x_31 + x_3) % m1;
	return (double)x_3;
}


void extEuclid(long a, long b, long *x, long *y, long *d) {//calculates greatest common divisor of a and b
	long q, r, x1, x2, y1, y2;
	if (b == 0) {
		*d = a, *x = 1, *y = 0;
	}
	x2 = 1, x1 = 0, y2 = 0, y1 = 1;
	while (b > 0) {
		q = a / b, r = a - q * b;
		*x = x2 - q * x1, *y = y2 - q * y1;
		a = b, b = r;
		x2 = x1, x1 = *x, y2 = y1, y1 = *y;
	}
	*d = a, *x = x2, *y = y2;
}

int inverse(long a, long n) {// inverse of a modulo n
	long d, x, y;
	extEuclid(a, n, &x, &y, &d);
	if (d == 1) return (double)x;
	return 0;
}

double congruentialSequence(unsigned int x_4) {//p???
	x_4 = ((inverse(x_4, p))*a2 + c2) % p;
	return (double)x_4;
}

double unions(unsigned int x_5) {

	x_5 = linearCongruent(x_5);
	unsigned int y = quadraticCongruent(x_5);
	if (x_5 >= y) { return (double)((x_5 - y) % m1); }
	else return (double)((y - x_5) % m2);
}

double threeSigma(unsigned int x_6) {
	
	double sum = 1;
	for (int i = 1; i < 12; i++) {
		sum += linearCongruent(sum)/107.;
	}
	x_6 = (median + (sum - 6)*sigma);
	return (double)x_6;
}

double polarCoordinates(unsigned int &x_7) {
	while (1)
	{
		x_7 = linearCongruent(x_7);
		double u1 =(double) x_7/m1;
		double u2 = quadraticCongruent(x_7)/m2;
		double v1 = 2 * u1 - 1;
		double v2 = 2 * u2 - 1;
		cout << "u" << u1 << "v" << v1<<endl;
		double s = v1*v1 + v2*v2;
		if (s >= 1) { continue; 
		cout << "aaA";
		}
		double x_71 = v1*sqrt(-2 * log(s) / s);
		double x_72 = v2*sqrt(-2 * log(s) / s);
		return (x_71 >= x_72) ? ((double)x_71) : ((double)x_72);
		
	}

}

double relations(unsigned int x_8) {
	while (1) {
		double u = linearCongruent(x_8)/m1;
		if ((x_8*x_8) > (-4 * log(u)))
			continue;
		double v = quadraticCongruent(x_8)/m2;
		if (u != 0) {
			double x_8 = (sqrt(8 / e)*((v - 0.5) / u));
			if ((x_8*x_8) <= (5 - 4 * (pow(e, 0.25)*u))) {
				return (double)x_8;
				goto AWAY;
			}
		}
	}AWAY:;
}

double logarithm(unsigned int x_9) {
	x_9=linearCongruent(x_9)/m1;
	if (x_9 != 0) x_9 = -mu*log(x_9);
	return (double)x_9;
}

double ahrens(unsigned int u) {
	while (1) {
		u = linearCongruent(u)/m1;
		double y = tan(u*pi);
		double x_10 = sqrt(2 * a3 - 1)*y + a3 - 1;
		if (x_10 <= 0) {
			continue;
			cout << "aaa";
		}
		double v = linearCongruent(u)/m1;
		return (double)x_10;
	}
}