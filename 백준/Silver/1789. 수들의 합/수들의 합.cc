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

unsigned long long s;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
}

void SOLVE()
{
	unsigned long long ans = 0;
	for (unsigned long long i = 1; ; i++)
	{
		if (i * (i + 1) / 2 > s)
		{
			ans = i;
			break;
		}
	}
	cout << ans - 1;
}

int main()
{
	INPUT();

	SOLVE();
}