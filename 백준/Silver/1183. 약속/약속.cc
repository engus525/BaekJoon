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

int n;
int a[51], b[51];
vector<int> v;

void INPUT()
{
   IAMFAST
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> a[i] >> b[i];
      v.emplace_back(a[i] - b[i]);
   }
}


void solution()
{
   sort(v.begin(), v.end());

   if (n % 2) cout << 1;
   else cout << v[n / 2] - v[n / 2 - 1] + 1;
}

int main()
{
   INPUT();
   solution();
}