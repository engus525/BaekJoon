#include <iostream>
#include <vector>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
char map[51][51];

int dp[51][51];
bool dpFixed[51][51],visited[51][51];
typedef pair<int,int> pii;
pii dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void INPUT()
{
	//IAMFAST
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%1s",&map[i][j]);
}


int DFS(int x,int y)
{
	if(map[x][y] == 'H') return 0;
	if(!(0<=x&&x<n&&0<=y&&y<m)) return 0;
	if(dpFixed[x][y]) return dp[x][y];
	if(visited[x][y]) cout << -1 , exit(0);

	visited[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int nx = x + (map[x][y]-'0')*dir[i].first;
		int ny = y + (map[x][y]-'0')*dir[i].second;
		dp[x][y] = max(dp[x][y],DFS(nx,ny)+1);
	}
	visited[x][y] = false;
	dpFixed[x][y] = true;
	return dp[x][y];
}

void SOLVE()
{
	cout  << DFS(0,0);
}

int main()
{
	INPUT();
	SOLVE();
}