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
vector<ll> x, ps;

void INPUT()
{
   IAMFAST
   cin >> n;
   x.resize(n), ps.resize(n);
   for (int i = 0; i < n; i++) cin >> x[i];
}


void solution()
{
   sort(x.begin(), x.end());
   ps[0] = x[0];
   for (int i = 1; i < n; i++) ps[i] = ps[i - 1] + x[i];

   ll ans = 0;
   for (int i = 0; i < n - 1; i++)
   {
//      cout << i << " -> x[" << i + 1 << "]  : " << x[i + 1] << " , ps[" << i << "] : " << ps[i] << '\n';
//      cout << x[i + 1] << " " << ps[i] << '\n';
//      cout << (i + 1) * x[i + 1] - ps[i] << '\n';
      ans += (i + 1) * x[i + 1] - ps[i];
   }
   cout << ans * 2;
}


int main()
{
   INPUT();
   solution();
}