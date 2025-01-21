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

int n;
pii graph[30];

void INPUT()
{
   IAMFAST
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      char a, b, c; cin >> a >> b >> c;
      graph[a - 'A'] = { -1, -1};
      if (b != '.') graph[a - 'A'].first = b - 'A';
      if (c != '.') graph[a - 'A'].second = c - 'A';
   }
}

void travel(int now, int mode)
{
   if (mode == 1)
   {
      cout << char(now + 'A');
      auto [l, r] = graph[now];
      if (l != -1) travel(l, mode);
      if (r != -1) travel(r, mode);
   }
   else if (mode == 2)
   {
      auto [l, r] = graph[now];
      if (l != -1) travel(l, mode);
      cout << char(now + 'A');
      if (r != -1) travel(r, mode);
   }
   else if (mode == 3)
   {
      auto [l, r] = graph[now];
      if (l != -1) travel(l, mode);
      if (r != -1) travel(r, mode);
      cout << char(now + 'A');
   }
}

void solution()
{
   travel(0, 1); cout << '\n';
   travel(0, 2); cout << '\n';
   travel(0, 3);
}

int main()
{
   INPUT();
   solution();
}