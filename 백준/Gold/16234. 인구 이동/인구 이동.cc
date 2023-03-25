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

int n, L, R;

int map[51][51];
int unite[51][51]; // 연합을 수로 표기
bool visited[51][51];
int sum = 0;

vector<pair<int, int>> v;// 연합국

int ans = 0;

void INPUT()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> L >> R;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

void openLine(pair<int,int> Pos) // 이전.현재xy좌표
{// 국경선 열기 (DFS 방식)

	v.push_back(make_pair(Pos.first, Pos.second));
	sum += map[Pos.first][Pos.second];
	visited[Pos.first][Pos.second] = true;

	int nx[4] = { -1, 1, 0, 0 };
	int ny[4] = { 0, 0, -1, 1 }; // 상-하-좌-우
	for (int i = 0; i < 4; i++)
	{
		int nX = Pos.first + nx[i], nY = Pos.second + ny[i];

		if (0 <= nX && nX < n && 0 <= nY && nY < n)
		{// 지도 범위 안에 있으며
			if (L <= abs(map[Pos.first][Pos.second] - map[nX][nY]) &&
				abs(map[Pos.first][Pos.second] - map[nX][nY]) <= R)
			{ // L과 R 범위내에 있고
				if (!visited[nX][nY])// 방문하지 않았다면
				{
					openLine(make_pair(nX, nY));// 국경선 열기
				}
					
			}
		}
		
	}

}


void movePeople()
{// 인구 이동

	for (int i = 0; i < v.size(); i++)
		map[v[i].first][v[i].second] = sum / v.size();
}


void solve()
{
	
	while (1)
	{
		//초기화
		memset(visited, false, sizeof(visited));
		bool needMove = false;

		//인구 이동 시작

		//국경선 열기
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				if (!visited[i][j])
				{
					openLine(make_pair(i, j));
					if (v.size() > 1)
					{
						needMove = true;
						movePeople();
					}
					v.clear(); // 연합이 아닌 국가끼리 push되는 것을 방지
					sum = 0;
				}
		}

		if (needMove) ans++;
		else break;
	}
	
	cout << ans;

}

int main()
{

	//system("mode con cols=60 lines=40 | title 아~너무쉽다");
	INPUT();

	solve();
}