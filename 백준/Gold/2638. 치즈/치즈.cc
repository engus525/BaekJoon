#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int map[101][101];

int cnt[101][101];//[i][j]칸 치즈에 공기가 접촉하는 변의 수
bool visited[101][101];
typedef pair<int,int> pii;
vector<pii> melt;
pii dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void INPUT()
{
	IAMFAST
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> map[i][j];
}

void BFS()
{
	queue<pii> q;
	q.push({0,0});
	visited[0][0] = true;

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;
			if(!(0<=nx&&nx<n&&0<=ny&&ny<m)) continue;
			if(visited[nx][ny]) continue;

			if(map[nx][ny] && (cnt[nx][ny] < 2))
			{//치즈에 외부 공기가 닿으면 && 중복 push방지
				cnt[nx][ny]++;
				if(cnt[nx][ny] == 2)
					melt.push_back({nx,ny});
			}

			if(!map[nx][ny])
			{
				visited[nx][ny] = true;
				q.push({nx,ny});
			}
		}
	}
}

void SOLVE()
{
	int ans = 0;
	while(true)
	{
		BFS();
		memset(visited,false,sizeof visited);
		memset(cnt,0,sizeof cnt);
		if(melt.empty()) break;

		ans++;

		for(int i = 0; i < melt.size(); i++)
			map[melt[i].first][melt[i].second] = 0;
		melt.clear();
	}
	cout << ans;
}

int main()
{
	INPUT();
	SOLVE();
}