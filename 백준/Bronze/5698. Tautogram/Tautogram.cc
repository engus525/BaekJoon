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

string str;

void INPUT()
{
  IAMFAST
}

bool Tautogram()
{
  vector<char> v;
  v.emplace_back(str[0]);
  for (int i = 1; i < str.length(); i++)
    if (str[i] == ' ') v.emplace_back(str[i + 1]);

  for (auto &c : v)
    if (tolower(str[0]) != tolower(c)) return false;
  return true;
}

void solution()
{
  while (getline(cin, str))
  {
    if (str == "*") break;

    cout << (Tautogram() ? "Y\n" : "N\n");
  }

}


int main()
{
  INPUT();
  solution();
}