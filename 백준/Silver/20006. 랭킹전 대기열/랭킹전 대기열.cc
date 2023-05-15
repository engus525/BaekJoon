#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int p, m, level;
string nick;
typedef pair<int, string> pis;
vector<pis> v[300];

void INPUT()
{
    IAMFAST
    cin >> p >> m;
}


void SOLVE()
{
    int cnt = 0;
    while (p--)
    {
        cin >> level >> nick;

        bool entered = false;
        for (int i = 0; i < cnt; i++)
        {
            if (v[i].size() == m) continue;
            if (abs(v[i][0].first - level) > 10) continue;
            v[i].emplace_back(level, nick);
            entered = true;
            break;
        }

        if (!entered) v[cnt].emplace_back(level, nick), cnt++;
    }

    for (int i = 0; i < cnt; i++)
    {
        if (v[i].size() == m)cout << "Started!\n";
        else cout << "Waiting!\n";

        sort(v[i].begin(), v[i].end(),
             [](pis a, pis b)
             {
                 return a.second < b.second;
             });
        for (auto j: v[i])
            cout << j.first << " " << j.second << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}