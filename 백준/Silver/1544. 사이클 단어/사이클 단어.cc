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
unordered_set<string> S;

void INPUT()
{
  IAMFAST
  cin >> n;
}

void solution()
{
  while (n--)
  {
    string str;
    cin >> str;

    bool exist = false;
    for (int i = 0; i < str.length(); i++)
    {
      if (S.count(str.substr(i) + str.substr(0, i)))
      {
        exist = true;
        break;
      }
    }

    if (!exist) S.emplace(str);
  }

  cout << S.size();
}


int main()
{
  INPUT();
  solution();
}