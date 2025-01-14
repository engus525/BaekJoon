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

int n, m;
int cnt[100001];

void INPUT()
{
  IAMFAST
  cin >> n >> m;
}


void solution()
{
  for (int i = 0; i < m; i++)
  {
    int a, b; cin >> a >> b;
    cnt[a]++, cnt[b]++;
  }
  for (int i = 0; i < n; i++) cout << cnt[i + 1] << '\n';
}


int main()
{
  INPUT();
  solution();
}