#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100'000;

int n, k;
bool visited[100'001];
queue<pair<int, int>> q;//<좌표, 초>

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
}

int BFS()
{
	q.push({n,0});
	visited[n] = true;

	while (!q.empty())
	{
		int now = q.front().first;
		int second = q.front().second;
        q.pop();
        
		if (now == k) return second;

		if (now + 1 <= MAX && !visited[now + 1])
		{
			q.push(make_pair(now + 1, second + 1));
			visited[now + 1] = true;
		}
		if (now - 1 >= 0 && !visited[now - 1])
		{
			q.push(make_pair(now - 1, second + 1));
			visited[now - 1] = true;
		}
		if (now * 2 <= MAX && !visited[now  * 2])
		{
			q.push(make_pair(now * 2, second + 1));
			visited[now * 2] = true;
		}
	}
}

void solve()
{
	cout << BFS();
}

int main()
{
	INPUT();
	solve();
}