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
#include <sstream>
using namespace std;
/* –2,147,483,648 ~ 2,147,483,647 */

int n, k;
string num;
deque<int> dq;

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> num;
}



void SOLVE()
{
	int eraseCnt = k;
	for (int i = 0; i < n; i++)
	{
		while (eraseCnt && !dq.empty() && dq.back() < num[i] - '0')
		{
			dq.pop_back();
			eraseCnt--;
		}
		dq.push_back(num[i] - '0');
	}// for end

	for (int i = 0; i < n - k; i++)
	{
		cout << dq.front();
		dq.pop_front();
	}

}

int main()
{
	INPUT();

	SOLVE();
}