#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // cpp
#include <stdio.h> // c
#include <string>
#include <memory.h> // memset
#include <algorithm>
#include <cmath>
// 자료 구조
#include <queue>
#include <vector>
#include <stack>
#include <set>
//#include <map>
using namespace std;

int a, b;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
}




void SOLVE()
{
	cout << (a + b) * (a - b);
}

int main()
{
	INPUT();

	SOLVE();
}