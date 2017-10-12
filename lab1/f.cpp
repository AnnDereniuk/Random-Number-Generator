#include <iostream>
#include<iomanip>
#include"generators.h"
#include "f.h"
using namespace std;


int choice() {
	int a = 0;
	cout << "Choose a type of generator:\n";
	cout << "1 - linear congruent\n";
	cout << "2 - quadratic congruent\n";
	cout << "3 - Fibonacci numbers\n";
	cout << "4 - congruential sequence\n";
	cout << "5 - method of unions\n";
	cout << "6 - the rule of three sigmas\n";
	cout << "7 - polar coordinates\n";
	cout << "8 - method of relations\n";
	cout << "9 - logarithm\n";
	cout << "10 - Ahrens\n";
	cin >> a;
	if (cin.fail()) {
		cin.clear(); cin.sync(); cin.ignore(1, '\n');
		return -1;
	}

	return a;
}


void invocation() {
	 double a, n, m=0.1;

		int b = choice();
		
		if (b <= 5) { 
			a = 0.0; n = 1.0; 
		}
		else {	
			if (b < 7) {
				a = -3.0; n = 3.0;
			}
			else a = 0.0; n = 100.0;
			}
		cout << "Interval" <<"     "<< "Frequence"<<endl;
		double t = 0; 

		int N = 100000; const int k1 = 10, k2 = 60, k3 = 1000;

		switch (b) {
		case 1: {
			int q[k1];
			double sum=0;
			unsigned int x = 0;
			for (int i = 0; i < k1; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = linearCongruent(x);
				t = (double)x / (double)107;
				++q[(int)(t * k1)];
			}
			for (int i = 0; i < k1; ++i) {

				cout << "[" << fixed << setprecision(1) << a + i*m
					<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(6)
					<< q[i] / (double)N << endl;
				sum = sum + q[i]/((double)N);
			} 
			cout << "sum="<<sum<<endl;
			break;
		}

		case 2: {
			int q[k1];
			double x = 0;
			for (int i = 0; i < k1; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = linearCongruent(x);
				t = (double)x / (double)107;
				++q[(int)(t * k1)];
			}
			for (int i = 0; i < k1; ++i)
				cout << "[" << fixed << setprecision(1) << a + i*m
				<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(6)
				<< q[i] / (double)N << endl;
			break;
		}

		case 3: {
			int q[k1];
			unsigned int x = 0;
			for (int i = 0; i < k1; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = fibonacciNumbers(x);
				t = (double)x / (double)107;
				++q[(int)(t * k1)];
			}
			for (int i = 0; i < k1; ++i)
				cout << "[" << fixed << setprecision(1) << a + i*m
				<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(6)
				<< q[i] / (double)N << endl;
			break;
		}

		case 4: {//0 1
			int q[k1];
			unsigned int x = 1;
			for (int i = 0; i < k1; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = congruentialSequence(x);
				t = (double)x / (double)571;
				++q[(int)(t * k1)];
			}
			for (int i = 0; i < k1; ++i)
				cout << "[" << fixed << setprecision(1) << a + i*m
				<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(6)
				<< q[i] / (double)N << endl;
			break;
		}

		case 5: {
			int q[k1];
			unsigned int x = 0;
			for (int i = 0; i < k1; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = unions(x);
				t = (double)x / (double)322701;
				++q[(int)(t * k1)];
			}
			for (int i = 0; i < k1; ++i)
				cout << "[" << fixed << setprecision(1) << a + i*m
				<< " , " << a + ((i + 1)*m) << "]" << "    " << setprecision(6)
				<< q[i] / (double)N << endl;
			break;
		}

		case 6: {//???
			int q[k2];
			unsigned int x = 1;
			for (int i = 0; i < k2; ++i)
			{q[i] = 0;}
			for (int i = 0; i <= N; ++i) {
		x = threeSigma(x);
		++q[(int)(x*k2)];
			}
	for (int i = 0; i < k2; ++i) {
		cout << "(" << fixed << setprecision(1) <<(double)(a+i*m) << " , " <<(double)(a + ((i + 1)*m)) << "]   ";
		cout << setprecision (6)<<q[i] / (double)N << "\n";
	}//(+3)*10*6(prom)
			
		/*x = threeSigma(x);
		t = (double)x / (double)107;
		++q[(int)(t * k2)];
		for (int i = 0; i < k2; ++i)
		cout << "[" << fixed << setprecision(1) << a + i*m
		<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(3)
		<< q[i] / (double)N << endl;
		*/
			break;
		}

		case 7: {//???empty
			int q[k3];
			/*unsigned int x = 0;
			for (int i = 0; i < k3; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = polarCoordinates(x);
				t = (double)x / (double)107;
				++q[(int)(t * k3)];
			}
			for (int i = 0; i < k3; ++i)
				cout << "[" << fixed << setprecision(1) << a + i*m
				<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(3)
				<< q[i] / (double)N << endl;
			break;
		}
			*/
			unsigned int x = 1;
			double rez;
			for (int i = 0; i < k3; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				rez = polarCoordinates(x);
				q[(int)rez *k3]+=1;
			}
			for (int i = 0; i < k3; ++i) {
				cout << "(" << fixed << setprecision(1) <<(double)i << " ; ";
				cout <<  setprecision(1) <<(double)i + 1 << "] ";
				cout <<fixed << setprecision(6) << q[i] / (double)N << "\n";
			}
			break;
		}
			

		case 8: {//??? empty
			int q[k3];
			unsigned int x = 1;
			for (int i = 0; i < k3; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = relations(x);
				q[(int)(x * k3)] += 1;
			}
			for (int i = 0; i < k3; ++i)
				cout << "[" << fixed << setprecision(1) << a + i*m<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(6)
				<< q[i] / (double)N << endl;
			break;
		}

		case 9: {//??? 0 1
			int q[k3];
			unsigned int x = 1;
			for (int i = 0; i < k3; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = logarithm(x);
				q[(int)(x)] += 1;
			}
			for (int i = 0; i < k3; ++i)
				cout << "[" << fixed << setprecision(1) << a + i*m<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(6)
				<< q[i] / (double)N << endl;
			break;
		}

		case 10: {//??? 0 1
			int q[k3];
			unsigned int x = 1;
			for (int i = 0; i < k3; ++i)
				q[i] = 0;
			for (int i = 0; i <= N; ++i) {
				x = ahrens(x);
				q[(int)(x * k3)] += 1;
			}
			for (int i = 0; i < k3; ++i)
				cout << "[" << fixed << setprecision(1) << a + i*m<< " , " << a + ((i + 1)*m) << "]" << "        " << setprecision(3)
				<< q[i] / (double)N << endl;
			break;
		}
		default: cout << "\nError\n";
	}
}

