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

int a1, a0, c, n0;

void INPUT()
{
   IAMFAST
   cin >> a1 >> a0 >> c >> n0;
}

void solution()
{
   if (c <= a1 && c * n0 <= a1 * n0 + a0) cout << 1;
   else cout << 0;
}

int main()
{
   INPUT();
   solution();
}