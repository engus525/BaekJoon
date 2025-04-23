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
struct Pos
{
    int x, y, r;
};
vector<Pos> v;
int parent[3001];
int ans;

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

   if (x == y) return;
   ans--;
   parent[y] = x;
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
      ans = n;
      for (int i = 1; i <= n; i++) parent[i] = i;
      v.clear();

      for (int i = 1; i <= n; i++)
      {
         int x, y, r;
         cin >> x >> y >> r;
         v.push_back({x, y, r});
      }

      for (int i = 0; i < n - 1; i++)
         for (int j = i + 1; j < n; j++)
            if (close(i, j)) Union(i+1, j+1);

      cout << ans << '\n';

   }

}

int main()
{
   INPUT();
   solution();
}