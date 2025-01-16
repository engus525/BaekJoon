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
pii cnt[100001];

void INPUT()
{
   IAMFAST
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> cnt[i].first;
      cnt[i].second = 1;
   }
}


void solution()
{
   sort(cnt, cnt + n);

   int ans = 0;

   pii now = {cnt[0].first, 0};
   for (int i = 0; i < n; i++)
   {
      now.second += cnt[i].second;
      if (now.first == now.second)
      {
         ans++;
         if (i != n - 1) now = {cnt[i + 1].first, 0};
         else
         {
            now.second = 0;
            break;
         }
      }
   }

   if (now.second) ans++;
   cout << ans;
}


int main()
{
   INPUT();
   solution();
}