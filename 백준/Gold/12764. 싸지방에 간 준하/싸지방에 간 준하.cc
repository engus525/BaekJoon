#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> v;
priority_queue<int, vector<int>, greater<>> blankSeat;
priority_queue<pii, vector<pii>, greater<>> pq;
int cnt[100001];
int seatNum = 1;

void INPUT()
{
   IAMFAST
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      int s, e;
      cin >> s >> e;
      v.emplace_back(s, e);
   }

}

void solution()
{
   sort(v.begin(), v.end());

   pq.emplace(v[0].second, seatNum);
   cnt[seatNum]++;
   for (int i = 1; i < v.size(); i++)
   {
      auto &[s, e] = v[i];

      while (!pq.empty() && s > pq.top().first)
      {
         blankSeat.emplace(pq.top().second);
         pq.pop();
      }

      if (blankSeat.empty())
      {
         pq.emplace(e, ++seatNum);
//         cout << s << " ~ " << e << " => " << seatNum << '\n';
         cnt[seatNum]++;
      }
      else
      {
         pq.emplace(e, blankSeat.top());
         cnt[blankSeat.top()]++;
//         cout << s << " ~ " << e << " => " << blankSeat.top() << '\n';
         blankSeat.pop();
      }
   }

   cout << seatNum << '\n';
   for (int i = 1; i <= seatNum; i++)
      cout << cnt[i] << " ";

}

int main()
{
   INPUT();
   solution();
}