#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int r,c;
char map[1501][1501];


typedef pair<int,int> pii;
vector<pii> L;
queue<pii> bird,water,q,nq;
pii dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
int visited1[1501][1501];
int visited2[1501][1501];


void INPUT()
{
	//IAMFAST
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		{
			scanf("%1s",&map[i][j]);
			if(map[i][j] == 'L')
				L.emplace_back(i,j),
				bird.push({i,j}),
				water.push({i,j});
			if(map[i][j] != 'X')
				water.push({i,j});
		}
}

bool inRange(int x,int y)
{
	return 0<=x&&x<r&&0<=y&&y<c;
}

void print2d()
{
	cout << '\n';
	for(int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << visited2[i][j];
		cout << '\n';
	}
}

bool BFS2()
{
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(L[1].first == x && L[1].second == y) return true;

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;

			if(!inRange(nx,ny)) continue;
			if(visited2[nx][ny]) continue;

			if(map[nx][ny] == 'X') nq.push({nx,ny});
			else q.push({nx,ny});
			visited2[nx][ny] = true;
		}
	}
	return false;
}

void BFS1()
{
	int wSize = water.size();
	while(wSize--)
	{
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;

			if(!inRange(nx,ny)) continue;
			if(visited1[nx][ny]) continue;

			if(map[nx][ny] == 'X')
			{
				map[nx][ny] = '.';
				water.push({ nx, ny });
				visited1[nx][ny] = true;
			}
		}
	}
}


void SOLVE()
{
	int ans = 0;
	q.push(L[0]);
	visited2[L[0].first][L[0].second] = true;
	while(true)
	{
		if(BFS2()) cout << ans , exit(0);
		ans++;
		BFS1();

		while(!nq.empty()) q.push(nq.front()),nq.pop();
	}
}

int main()
{
	INPUT();
	SOLVE();
}