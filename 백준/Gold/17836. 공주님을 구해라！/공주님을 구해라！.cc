#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m,t;
int map[101][101];

typedef pair<int,int> pii;
int visited [2][101][101];
pii dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};


void INPUT()
{
	IAMFAST
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> map[i][j];
}

bool inRange(int x,int y)
{
	return 0<x&&x<=n&&0<y&&y<=m;
}

int BFS()
{
	struct Soldier
	{
		int x;
		int y;
		bool gram;
	};
	queue<Soldier> q;
	q.push({1,1,false});
	visited[false][1][1] = 1;

	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		bool gram = q.front().gram;
		q.pop();

		//그람 획득
		if(map[x][y] == 2)
		{
			gram = true;
			visited[true][x][y] = visited[false][x][y];
		}
		//공주 구출
		if(x == n && y == m) return visited[gram][x][y];

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;

			if(!inRange(nx,ny)) continue;
			if(!gram && map[nx][ny] == 1) continue;

			if(gram && !visited[true][nx][ny])
				q.push({nx,ny,true}),
				visited[true][nx][ny] = visited[true][x][y] + 1;

			if(gram && !visited[false][nx][ny])
				q.push({nx,ny,true}),
				visited[false][nx][ny] = visited[true][x][y] + 1;
			else if(!gram && !visited[false][nx][ny])
				q.push({nx,ny,false}),
				visited[false][nx][ny] = visited[false][x][y] + 1;
		}
	}
	return 2e9;
}


void SOLVE()
{
	int time = BFS()-1;
	if(time <= t) cout << time;
	else cout <<"Fail";
}

int main()
{
	INPUT();
	SOLVE();
}