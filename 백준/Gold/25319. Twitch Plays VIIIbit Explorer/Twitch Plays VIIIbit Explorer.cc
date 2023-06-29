#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m, sLen;
vector<pair<int, int>> pos[26];
int cnt[26];
int sCnt[26];
string S;
string L;

void INPUT()
{
    //IAMFAST
    cin >> n >> m >> sLen;
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++)
        {
            cnt[row[j] - 'a']++;
            pos[row[j] - 'a'].emplace_back(i, j);
        }
    }
    cin >> S;
    for (int i = 0; i < sLen; i++)
        sCnt[S[i] - 'a']++;
}

void goPortal(int &x, int &y, string &l)
{
    while (n - 1 > x) l += "D", x++;
    while (m - 1 > y) l += "R", y++;
}

int getC()
{
    int C = 2e9;
    for (int i = 0; i < sLen; i++)
        C = min(C, cnt[S[i] - 'a'] / sCnt[S[i] - 'a']);
    return C;
}

void SOLVE()
{
    int C = getC();
    cout << C << " ";

    int x = 0, y = 0;
    while (C--)
    {
        for (int i = 0; i < sLen; i++)
        {
            auto [nx, ny] = pos[S[i] - 'a'].back();

            while (nx < x) L += "U", x--;
            while (nx > x) L += "D", x++;
            while (ny < y) L += "L", y--;
            while (ny > y) L += "R", y++;

            L += "P";
            pos[S[i] - 'a'].pop_back();
        }
    }

    goPortal(x, y, L);

    cout << L.length() << '\n' << L;
}

int main()
{
    INPUT();
    SOLVE();
}