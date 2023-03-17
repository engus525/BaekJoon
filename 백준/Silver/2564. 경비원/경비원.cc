#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stdio.h>
#include<ctime>
using namespace std;
/* 	–2,147,483,648 ~ 2,147,483,647 */

int n, m, shopNum;
vector<pair<int, int>> shop;
int ans = 0;
int x, y; // 동근이 위치

int donggeun()
{
	if (x == 1)
		return y;
	else if (x == 2)
		return 2 * n + m - y;
	else if (x == 3)
		return 2 * m + 2 * n - y;
	else return n + y;
}

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> shopNum;
	for (int i = 0; i < shopNum; i++)
	{
		int x, y; cin >> x >> y;
		shop.push_back(pair<int, int>(x, y));
	}
	cin >> x >> y;
}

void solve()
{
	int blockLen = 2 * n + 2 * m;
	int person = donggeun(), dist;
	for (int i = 0; i < shop.size(); i++)
	{
		// 1
		if (shop[i].first == 1)
			dist = abs(person - shop[i].second); // 상점과 동근이 거리

		// 2
		else if (shop[i].first == 2)
			dist = abs(person - (2 * n + m - shop[i].second));
		
		// 3
		else if (shop[i].first == 3)
			dist = abs(person - (2 * n + 2 * m - shop[i].second));

		// 4
		else if (shop[i].first == 4)
			dist = abs(person - (n + shop[i].second));
		ans += min(blockLen - dist, dist);
	}
	cout << ans;
}

int main()
{
	INPUT();

	solve();
}