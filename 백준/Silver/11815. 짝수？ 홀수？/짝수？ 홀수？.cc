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

void INPUT()
{
   IAMFAST
   cin >> n;
}


void solution()
{
   while (n--)
   {
      ll val; cin >> val;
      if (ll(sqrt(val)) * ll(sqrt(val)) == val) cout << 1 << " ";
      else cout << 0 << " ";
   }
}

int main()
{
   INPUT();
   solution();
}