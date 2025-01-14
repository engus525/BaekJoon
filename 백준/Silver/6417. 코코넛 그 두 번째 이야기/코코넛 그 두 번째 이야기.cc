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

void INPUT()
{
  IAMFAST
}

void solution()
{
  while (cin >> n)
  {
    if (n == -1) return;

    bool flag = false;
    for (int i = n; i > 1; i--)
    {
      if ((n - 1) % i) continue;

      int copyN = n;
      int cnt = 0;
      while (true)
      {
//        cout << "N : " << copyN << " , " << "i : " << i << '\n';
        if (copyN <= 0) break;
        if ((copyN - 1) % i) break;
        copyN -= (copyN - 1) / i + 1;
        cnt++;
      }

//      cout << "cnt : " << cnt << '\n';
      if (cnt == i && !(copyN % i))
      {
        flag = true;
        cout << n << " coconuts, " << i << " people and 1 monkey\n";
        break;
      }

    }
    if (!flag) cout << n << " coconuts, no solution\n";
  }

}


int main()
{
  INPUT();
  solution();
}