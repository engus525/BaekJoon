#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int map[21][21];

typedef pair<int,int> pii;
pii dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visited[21][21];
struct Block
{
	int size = 0;
	int rainbow = 0;
	pii standard;//기준 블록
};
//제거할 블록 정렬 기준
struct comp
{
	bool operator()(Block a, Block b)
	{
		if (a.size == b.size)
		{
			if (a.rainbow == b.rainbow)
			{
				if (a.standard.first == b.standard.first)
					return a.standard.second < b.standard.second;
				else return a.standard.first < b.standard.first;
			}
			else return a.rainbow < b.rainbow;
		}
		else return a.size < b.size;
	}
};
priority_queue<Block,vector<Block>,comp> pq;

void INPUT()
{
	IAMFAST
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j= 1; j <= n; j++)
			cin >> map[i][j];
}

void Delete(pii pos,int color)
{
	int x = pos.first;
	int y = pos.second;

	visited[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;

		if(!(1<=nx&&nx<=n&&1<=ny&&ny<=n)) continue;
		if(visited[nx][ny]) continue;
		if(map[nx][ny] == -1e9) continue;
		if(map[nx][ny] == -1) continue;
		if(map[nx][ny] >= 1 && map[nx][ny]!=color) continue;

		Delete({ nx, ny },color);
	}
	map[x][y] = -1e9;
}

void Gravity()
{
	for(int i = n-1; i >= 1; i--)
		for(int j= 1; j <= n; j++)
		{
			if(map[i][j] == -1) continue;
			if(map[i][j] == -1e9) continue;

			int process = i;
			while(true)
			{
				if(process+1 > n) break;
				if(map[process+1][j] != -1e9) break;

				map[process+1][j] = map[process][j];
				map[process][j] = -1e9;
				process++;
			}
		}
}

void Turn()
{
	int copy[21][21];
	for(int i = 1; i <= n; i++)
		for(int j= 1; j <= n; j++)
			copy[i][j] = map[i][j];
	for(int i = 1; i <= n; i++)
		for(int j= 1; j <= n; j++)
			map[n+1-j][i] = copy[i][j];
}


pii DFS(int x,int y,int color)
{

	int size = 1;
	int rainbow = (map[x][y] == 0) ? 1 : 0;

	visited[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;

		if(!(1<=nx&&nx<=n&&1<=ny&&ny<=n)) continue;
		if(visited[nx][ny]) continue;
		if(map[nx][ny] == -1e9) continue;
		if(map[nx][ny] == -1) continue;
		if(map[nx][ny] >= 1 && map[nx][ny]!=color) continue;

		pii get = DFS(nx,ny,color);
		size += get.first;
		rainbow += get.second;
	}

	return {size,rainbow};
}

void printQ()
{
	priority_queue<Block,vector<Block>,comp> q;
	while(!pq.empty())
	{
		cout << pq.top().standard.first << "," << pq.top().standard.second << " "
		<< pq.top().size << '\n';
		q.push(pq.top());
		pq.pop();
	}
	while(!q.empty()) pq.push(q.top()),q.pop();
}

void print2d()
{
	for(int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(map[i][j] == -1e9) cout << "X" << " ";
			else if(map[i][j] == -1) cout << "-" << " ";
			else cout << map[i][j] << " ";
		}
		cout << '\n';
	}

}
void SOLVE()
{
	int ans = 0;
	while(true)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(!visited[i][j] && 1<=map[i][j])
				{
					pii dfs = DFS(i, j, map[i][j]);
					if(dfs.first >= 2)
						pq.push({ dfs.first, dfs.second, { i, j }});

					//무지개 블록은 중복될 수 있음
					for(int a = 1; a <= n; a++)
						for(int b = 1; b <= n; b++)
							if(map[a][b] == 0) visited[a][b] = false;
				}
		if(pq.empty()) break;
		//printQ();

		memset(visited,false,sizeof visited);
		ans += pq.top().size * pq.top().size;
		Delete(pq.top().standard,map[pq.top().standard.first][pq.top().standard.second]);
		while(!pq.empty()) pq.pop();
		memset(visited,false,sizeof visited);

		//print2d();

		Gravity();
		//cout << "\n중력1-------------\n"; print2d();
		Turn();
		//cout << "\n회전-------------\n"; print2d();
		Gravity();
		//cout << "\n중력2-------------\n"; print2d();
	}
	cout << ans;
}

int main()
{
	INPUT();
	SOLVE();
}