#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
vector<int> graph[2001];
bool visited[2001];

void INPUT()
{
   IAMFAST
   cin >> n >> m;
   for (int i = 0; i < m; i++)
   {
      int a, b; cin >> a >> b;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
   }
}

int dfs(int now)
{
   int maxSize = 0;
   visited[now] = true;

   for (int i = 0; i < graph[now].size(); i++)
   {
      int next = graph[now][i];
      if (visited[next]) continue;
//      cout << now << " --> " << next << '\n';

      int size = 1;
      visited[next] = true;
      size += dfs(next);
      visited[next] = false;

      maxSize = max(maxSize, size);
      if (maxSize >= 4) break;
   }

   return maxSize;
}

void solution()
{
   int maxV = 0;
   for (int i = 0; i < n; i++)
   {
      memset(visited, false, sizeof visited);
      int v = dfs(i) + 1;
//      cout << "return : " << v << "\n--------------\n";
      maxV = max(maxV, v);
   }
   cout << (maxV >= 5 ? 1 : 0);
}

int main()
{
   INPUT();
   solution();
}