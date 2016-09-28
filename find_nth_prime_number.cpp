// find_nth_prime_number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "math.h"
#include <time.h>
#include <fstream>
using namespace std;

int get_nth_prime_number(int n){
	int i, j;
	int *prime = new int[1000000];
	int k = 0;
	prime[k++] = 2;
	for (i = 3; k <= n; i = i + 2)
	{
		for (j = 0; prime[j] * prime[j] <= i; j++)
		{
			if (i%prime[j] == 0)break;
		}
		if (prime[j] * prime[j] > i)
		{
			prime[k++] = i;
		}
	}
	return prime[k - 2];
}

int _tmain(int argc, _TCHAR* argv[])
{

	int n, m;
	int x[7] = { 1, 10, 100, 1000, 10000, 100000, 1000000 }, y[7] = { 2, 29, 541, 7919, 104729, 1299709, 15485863 };
	int xx[3] = { 10000, 100000, 1000000 };
	char test;
	char *path = "C:\\Users\\v-panz\\Documents\\Visual Studio 2013\\Projects\\find_nth_prime_number\\results.txt";
	clock_t start, finish;
	cout << "run test code?(y/n)" << endl;
	cin >> test;
	if (test == 'y' || test == 'Y'){
		bool flag = 1;;
		for (int c = 0; c < 7; c++){
			int a;
			a = get_nth_prime_number(x[c]);
			cout << "the " << x[c] << "th prime number is:" << a << "    groudtrue is:" << y[c] <<endl;
			if (y[c] != a) flag = 0;
		}
		if (flag = 1) cout << "the code is right!" << endl;
		else 
			cout << "the code is wrong!" << endl;
	}
	ofstream fp(path, ios_base::out);
	if (fp.fail()) cout << "open fail.";
	for (int num = 0; num < 3; num++){
		n = xx[num];
		start = clock();
		m = get_nth_prime_number(n);
		cout << n << "th prime number:" << m << endl;
		finish = clock();
		cout << "use time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
		fp << m <<endl;
	}
	fp.close();
	return 0;
}
