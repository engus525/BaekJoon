#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int t, n;
unordered_set<int> S;
struct Pos
{
    int x, y, r;
};
vector<Pos> v;
int parent[3001];

void INPUT()
{
   IAMFAST
   cin >> t;
}

int Find(int x)
{
   if (x == parent[x]) return x;
   return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
//   cout << "Union " << x << " and " << y << '\n';
   x = Find(x);
   y = Find(y);

   for (int i = 1; i <= n; i++)
      if (parent[i] == y) parent[i] = x;
}

bool close(int i, int j)
{
   double dist = sqrt((v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y));
   double rDist = (v[i].r+v[j].r);
   return dist <= rDist;
}

void solution()
{
   while (t--)
   {
      cin >> n;
      for (int i = 1; i <= n; i++) parent[i] = i;
      v.clear();
      S.clear();

      for (int i = 1; i <= n; i++)
      {
         int x, y, r;
         cin >> x >> y >> r;
         v.push_back({x, y, r});
      }

      for (int i = 0; i < n - 1; i++)
         for (int j = i + 1; j < n; j++)
            if (close(i, j)) Union(i+1, j+1);

      for (int k = 1; k <= n; k++)
         S.emplace(parent[k]);
      cout << S.size() << '\n';

   }

}

int main()
{
   INPUT();
   solution();
}