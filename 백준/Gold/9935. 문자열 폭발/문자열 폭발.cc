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

string str;
string bomb;

string ans = "";

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str >> bomb;
}

void explode(int idx)
{
	//폭발 문자열이 더 길다면 폭발하지 않음
	if (ans.length() < bomb.length()) return;

	int cnt = 1;
	for (int i = 0; i < bomb.length() - 1; i++)
	{
		if (ans[idx - 1 - i] == bomb[bomb.length() - 2 - i])
			cnt++;
		else break;
	}
	
	if (cnt == bomb.length())
	{// 폭발 문자열이 있다면
		for (int i = 0; i < bomb.length(); i++)
			ans.pop_back();
	}
	else return;
}

void SOLVE()
{
	for (int i = 0; i < str.length(); i++)
	{
		ans += str[i];

		if (str[i] == bomb[bomb.length() - 1]) explode(ans.length() - 1);
	}
	if (ans != "") cout << ans;
	else cout << "FRULA";
	
}

int main()
{
	//system("mode con cols=60 lines=300 | title 아~너무쉽다");
	INPUT();

	SOLVE();
}