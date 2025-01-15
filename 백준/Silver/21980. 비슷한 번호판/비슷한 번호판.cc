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

int t;

void INPUT()
{
   IAMFAST
   cin >> t;
}

ll factorial(int n)
{
   ll res = 0;
   for (ll i = 1; i <= n; i++) res += i;
   return res;
}


void solution()
{
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      int upperCnt[10001];
      int alphaCnt[10001][30];
      memset(upperCnt, 0, sizeof upperCnt);
      memset(alphaCnt, 0, sizeof alphaCnt);
      string str[10001];
      for (int i = 0; i < n; i++)
      {
         cin >> str[i];
         for (auto &c: str[i])
         {
            if ('A' <= c && c <= 'Z') upperCnt[i]++;
            alphaCnt[i][tolower(c) - 'a']++;
         }
      }

      int ans = 0;
      bool visited[10001];
      for (int i = 0; i < n; i++)
      {
         int groupAns = 0;
         if (visited[i]) continue;
         for (int j = i + 1; j < n; j++)
         {
            if (upperCnt[i] != upperCnt[j]) continue;
            bool sameCnt = true;
            for (int k = 0; k < m; k++)
               if (alphaCnt[i][tolower(str[i][k]) - 'a']
                   != alphaCnt[j][tolower(str[i][k]) - 'a'])
                  sameCnt = false;

            if (sameCnt)
            {
//               cout << i << " and " << j << " SAME\n";
               visited[j] = true;
               groupAns++;
//               ans++;
            }
         }

         ans += factorial(groupAns);
      }
      cout << ans << '\n';

   }
}


int main()
{
   INPUT();
   solution();
}