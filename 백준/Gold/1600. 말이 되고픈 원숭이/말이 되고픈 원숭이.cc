#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int k,w,h;
int map[201][201];

int visited[31][201][201];
typedef pair<int,int> pii;
pii horse[8] = {{-2,1},{-1,2},
				{2,1},{1,2},
				{-2,-1},{-1,-2},
				{2,-1},{1,-2}};
pii dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void INPUT()
{
	IAMFAST
	cin >> k >> w >> h;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			cin >> map[i][j];
}

bool PASS(int cnt,int nx,int ny)
{
	if(!(0<=nx&&nx<h&&0<=ny&&ny<w)) return true;
	if(visited[cnt][nx][ny] != -1) return true;
	if(map[nx][ny] == 1) return true;
	return false;
}

int BFS()
{
	struct monkey
	{
		int x;
		int y;
		int cnt;
	};
	queue<monkey> q;
	q.push({0,0,k});
	visited[k][0][0] = 0;

	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		if(x==h-1&&y==w-1) return visited[cnt][x][y];
		q.pop();

		for(int i = 0; i < 8+4; i++)
		{
			int nx,ny;
			if(i < 8 && cnt)
			{
				nx = x + horse[i].first;
				ny = y + horse[i].second;
				if(PASS(cnt-1,nx,ny)) continue;
				q.push({ nx, ny, cnt - 1 });
				visited[cnt - 1][nx][ny] = visited[cnt][x][y] + 1;
			}
			else if(7 < i && i < 12)
			{
				nx = x + dir[i - 8].first;
				ny = y + dir[i - 8].second;
				if(PASS(cnt,nx,ny)) continue;
				q.push({ nx, ny, cnt });
				visited[cnt][nx][ny] = visited[cnt][x][y] + 1;
			}
		}
	}
	return -1;
}

void SOLVE()
{
	fill(&visited[0][0][0],&visited[k][h][w],-1);
	cout << BFS();
}

int main()
{
	INPUT();
	SOLVE();
}