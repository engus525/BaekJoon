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

bool submit[31];
void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 28; i++)
	{
		int num; cin >> num;
		submit[num] = true;
	}
}


void solve()
{
	for (int i = 1; i <= 30; i++)
	{
		if (!submit[i]) cout << i << "\n";
	}
}

int main()
{

	//system("mode con cols=60 lines=40 | title 아~너무쉽다");
	INPUT();

	solve();
}