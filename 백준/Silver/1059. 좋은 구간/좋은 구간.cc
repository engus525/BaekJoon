#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <memory.h> // memset
#include <numeric>
#include <stack>
using namespace std;
/* –2,147,483,648 ~ 2,147,483,647 */

int l, n;
int S[51];

int Min, Max;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x; cin >> x;
		S[i] = x;
	}
	sort(S, S + l);
	cin >> n;

}

void findMinMax()
{
	if (S[0] > n)
	{
		Min = 1; Max = S[0] - 1; return;
	}
	else if (S[l - 1] < n)
	{
		Min = S[l - 1] + 1; Max = 1000; return;
	}

	for (int i = 0; i < l - 1; i++)
	{
		if (n == S[i] || n == S[i + 1])
		{
			Min = 0; Max = 0; return;
		}
		if (S[i] < n && n < S[i + 1])
		{
			Min = S[i] + 1; Max = S[i + 1] - 1; return;
		}
	}
}

void solve()
{

	findMinMax();

	if (Min == 0)
		cout << 0;
	else cout << (n - 1 - Min + 1) * (Max - n + 1) + (Max - (n + 1) + 1);

}

int main()
{

	//system("mode con cols=60 lines=40 | title 아~너무쉽다");
	INPUT();

	solve();
}