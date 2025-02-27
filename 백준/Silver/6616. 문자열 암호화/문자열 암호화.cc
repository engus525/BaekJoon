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
string plain;

void INPUT()
{
   IAMFAST
}

void solution()
{
   while (cin >> n)
   {
      if (!n) break;

      cin.ignore();
      getline(cin, plain);
      string newPlain;
      for (auto c : plain)
      {
         if (c == ' ') continue;
         else if ('a' <= c && c <= 'z') newPlain += toupper(c);
         else newPlain += c;
      }
//      cout << "PLAIN : " << newPlain << '\n';

      vector<pair<int,char>> v;

      int startIdx = 0;
      int nowIdx = 0;
      int plainIdx = 0;
      while (v.size() < newPlain.length())
      {
         if (nowIdx >= newPlain.length())
         {
            startIdx++;
            nowIdx = startIdx;
            continue;
         }
         v.push_back({nowIdx, newPlain[plainIdx++]});
         nowIdx += n;
      }

      sort(v.begin(), v.end());
      for (auto c : v) cout << c.second;
      cout << '\n';
   }

}

int main()
{
   INPUT();
   solution();
}