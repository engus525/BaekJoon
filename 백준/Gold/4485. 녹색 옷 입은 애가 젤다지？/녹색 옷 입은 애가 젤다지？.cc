#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int map[126][126];

typedef pair<int,int> pii;
pii dir[4] = {{-1,0},
			  {1,0},
			  {0,-1},
			  {0,1}};
int dist[126][126];

void INPUT()
{
	IAMFAST
}

void ijk()
{
	struct Pos
	{
		int rupee;
		int x;
		int y;
	};
	struct comp
	{
		bool operator()(Pos a,Pos b)
		{
			if(a.rupee==b.rupee)
			{
				if(a.x==b.x) return a.y < b.y;
				return a.x < b.x;
			}
			return a.rupee < b.rupee;
		};
	};
	priority_queue<Pos,vector<Pos>,comp> pq;
	pq.push({ -map[0][0],0,0 });
	dist[0][0] = map[0][0];

	while(!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int c1 = -pq.top().rupee;
		pq.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;
			int c2 = map[nx][ny] + c1;
			if(!(0<=nx&&nx<n&&0<=ny&&ny<n)) continue;

			if(dist[nx][ny] > c2)
			{
				dist[nx][ny] = c2;
				pq.push({-c2,nx,ny});
			}
		}
	}

}

void SOLVE()
{
	int tc = 1;
	while(cin >> n)
	{
		if(!n) break;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> map[i][j],
				dist[i][j] = 2e9;

		ijk();
		cout << "Problem " << tc++ << ": " << dist[n-1][n-1] << '\n';
	}
}

int main()
{
	INPUT();
	SOLVE();
}