#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
/******
 
 float으로 풀지말자..명심.. 무조건 double...


 ******/
double real[10001];
double maximum = 0.0;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> real[i];
	}//입력

	for (int i = 0; i < n; i++)
	{
		double temp = 1;
		for (int j = i; j < n; j++) 
		{
			temp *= real[j];
			maximum = max(maximum, temp);
		}
	}

	printf("%.3lf\n", maximum);
}