#include <iostream>
#include <string>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
string inp;
int map[1001][1001];

typedef pair<int,int> pii;
pii dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};//E W S N
int visited[1001][1001];
int cnt = 1;

void INPUT()
{
	IAMFAST
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> inp;
		for (int j = 0; j < m; j++)
		{
			switch (inp[j])
			{
			case 'E' : map[i][j] = 0; break;
			case 'W' : map[i][j] = 1; break;
			case 'S' : map[i][j] = 2; break;
			case 'N' : map[i][j] = 3; break;
			}
		}
	}
}

int DFS(int x,int y)
{
	visited[x][y] = cnt;

	int nx = x+dir[map[x][y]].first;
	int ny = y+dir[map[x][y]].second;

	if(!visited[nx][ny])
		visited[x][y] = min(visited[nx][ny],DFS(nx,ny));
	else visited[x][y] = visited[nx][ny];
	
	return visited[x][y];
}

void SOLVE()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!visited[i][j])
				if(DFS(i,j) == cnt) cnt++;
	cout << cnt-1;
}

int main()
{
	INPUT();
	SOLVE();
}