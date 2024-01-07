#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int p, w;
string str;
map<char, pii> M;

void INPUT()
{
    IAMFAST
    cin >> p >> w;
    cin.ignore();
    getline(cin, str);
}

void makeBoard()
{
    M.insert({'A', {2, p}});
    M.insert({'B', {2, p * 2}});
    M.insert({'C', {2, p * 3}});

    M.insert({'D', {3, p}});
    M.insert({'E', {3, p * 2}});
    M.insert({'F', {3, p * 3}});

    M.insert({'G', {4, p}});
    M.insert({'H', {4, p * 2}});
    M.insert({'I', {4, p * 3}});

    M.insert({'J', {5, p}});
    M.insert({'K', {5, p * 2}});
    M.insert({'L', {5, p * 3}});

    M.insert({'M', {6, p}});
    M.insert({'N', {6, p * 2}});
    M.insert({'O', {6, p * 3}});

    M.insert({'P', {7, p}});
    M.insert({'Q', {7, p * 2}});
    M.insert({'R', {7, p * 3}});
    M.insert({'S', {7, p * 4}});

    M.insert({'T', {8, p}});
    M.insert({'U', {8, p * 2}});
    M.insert({'V', {8, p * 3}});

    M.insert({'W', {9, p}});
    M.insert({'X', {9, p * 2}});
    M.insert({'Y', {9, p * 3}});
    M.insert({'Z', {9, p * 4}});

    M.insert({' ', {1, p}});
}

void solution()
{
    makeBoard();

    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        ans += M[str[i]].second;
        if (i && M[str[i]].first == M[str[i - 1]].first && str[i] != ' ') ans += w;
        //cout << ans << '\n';
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}