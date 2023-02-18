#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,w;
double m;
typedef pair<double,double> pdd;
pdd pos[1001];
bool connected[1001][1001];

double dist[1001];

void INPUT()
{
	IAMFAST
	cin >> n >> w >> m;
	for(int i = 1; i <= n; i++)
		cin >> pos[i].first >> pos[i].second;
	for(int i = 0; i < w; i++)
	{
		int x,y; cin >> x >> y;
		connected[x][y] = true;
		connected[y][x] = true;
	}

}

double Distance(pdd a, pdd b)
{
	double first = pow(abs(a.first-b.first),2);
	double second = pow(abs(a.second-b.second),2);
	//cout << first << " " << second << '\n';
	return sqrt(first + second);
}

void printDist()
{
	for(int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	cout <<'\n';
}

void ijk()
{
	fill(dist+1,dist+1+n,2e9);
	priority_queue<pair<double,int>> pq;
	pq.push({0,1});
	dist[1] = 0;

	while(!pq.empty())
	{
		int now = pq.top().second;
		double x = pos[now].first;
		double y = pos[now].second;
		double d1 = -pq.top().first;
		pq.pop();

		for(int i = 1; i <= n; i++)
		{
			int next = i;
			double nx = pos[next].first;
			double ny = pos[next].second;
			double d2 = Distance({x,y},{nx,ny});

			if(connected[now][next]) d2 = 0;
			if(now == next) continue;
			if(d2 > m) continue;
			if(dist[next] <= d1+d2) continue;


			dist[next] = d1 + d2;
			//cout << now << " -> " << next << '\n';
			//cout << d1 << " , " << d2 << '\n';
			//printDist();
			pq.push({ -dist[i], i });
		}
	}
}

void SOLVE()
{
	ijk();
	cout << int(dist[n]*1000);
}

int main()
{
	INPUT();
	SOLVE();
}