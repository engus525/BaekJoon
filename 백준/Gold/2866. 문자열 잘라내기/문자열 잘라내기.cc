#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int r, c;
char graph[1001][1001];
unordered_set<string> S, newS;

void INPUT()
{
    IAMFAST
    cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < c; j++)
            graph[i][j] = str[j];
    }
}


void solution()
{
    for (int i = 0; i < c; i++)
    {
        string str;
        for (int j = r - 1; j >= 0; j--) str += graph[j][i];
        S.emplace(str);
    }

    int ans = 0;
    for (int i = 0; i < r - 1; i++)
    {
        bool fin = false;

        auto it1 = S.begin();
        for (; it1 != S.end(); it1++)
        {
            string str = *it1;
            str.pop_back();
            if (newS.find(str) == newS.end()) newS.insert(str);
            else
            {
                fin = true;
                break;
            }
        }

        if (fin) break;
        S = newS; newS.clear();
        ans++;
    }

    cout << ans;
}


int main()
{
    INPUT();
    solution();
}