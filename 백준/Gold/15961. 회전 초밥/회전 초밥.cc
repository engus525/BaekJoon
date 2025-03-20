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

int n, d, k, c;
int cnt[3001]; // 먹은 초밥 수
vector<int> sushi;

void INPUT()
{
   IAMFAST
   cin >> n >> d >> k >> c;
   for (int i = 0; i < n; i++)
   {
      int val; cin >> val;
      sushi.emplace_back(val);
   }
}

void Print(int &now)
{
   cout << "NOW : " << now << '\n';
   for (int i = 1; i <= d; i++)
      if (cnt[i]) cout << i << "를 " << cnt[i] << "개 먹음\n";
   cout << "============\n";
}

void solution()
{
   int ans = 0, now = 0;

   // 쿠폰은 무조건 먹음
   cnt[c] = 1, ans++, now++;

   int l = 0, r = k - 1;
   for (int i = 0; i <= r; i++)
   {
      cnt[sushi[i]]++;
      if (cnt[sushi[i]] == 1) ans++, now++;
   }

   while (l < n)
   {
//      Print(now);

      cnt[sushi[l]]--;
      if (cnt[sushi[l]] == 0) now--;

      l++, r++;

      cnt[sushi[r % n]]++;
      if (cnt[sushi[r % n]] == 1)
      {
         now++;
         ans = max(ans, now);
      }
   }

   cout << ans << '\n';
}

int main()
{
   INPUT();
   solution();
}