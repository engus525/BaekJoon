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
ll planet[300001];

void INPUT()
{
   IAMFAST
   cin >> n;
   for (int i = 0; i < n; i++) cin >> planet[i];
}


void solution()
{
   ll ans = planet[n - 1];
   for (int i = n - 2; i >= 0; i--)
   {
      if (ans < planet[i]) ans = planet[i];
      else if (ans > planet[i])
      {
         ll mul = (ans % planet[i]) ? ans / planet[i] + 1 : ans / planet[i];
         ans = mul * planet[i];
      }
   }
   cout << ans;
}


int main()
{
   INPUT();
   solution();
}