#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <map>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
int visited[100001];
int route[100001];

void INPUT()
{
   IAMFAST
   cin >> n >> k;
}

bool out(int next)
{
   if (next < 0 || next > 100000) return true;
   if (visited[next] != -1) return true;
   return false;
}

int bfs()
{
   queue<int> q;
   q.emplace(k);
   visited[k] = 0;

   while (!q.empty())
   {
      auto now = q.front();
      q.pop();

      if (now == n) return visited[now];

      int nextList[3] =
              {now - 1, now + 1, (now % 2) ? -1 : now / 2};

      for (int i = 0; i < 3; i++)
      {
         int next = nextList[i];

         if (out(next)) continue;
//         if (
//                 visited[nextList[i]] != -1 &&
//                 visited[nextList[i]] <= visited[now] + 1)
//            continue;

         // 목적지가 현재의 절반 이하면 /2 만
         if (!(now % 2) && n * 2 <= now && i != 2) continue;

         visited[next] = visited[now] + 1;
         route[next] = now;

         q.emplace(next);
      }
   }

   return q.front();
}

void solution()
{
   memset(visited, -1, sizeof visited);
   memset(route, -1, sizeof route);
   cout << bfs() << '\n';
   int idx = n;
   cout << n << " ";
   while (route[idx] != -1)
   {
      cout << route[idx] << " ";
      idx = route[idx];
   }
}

int main()
{
   INPUT();
   solution();
}