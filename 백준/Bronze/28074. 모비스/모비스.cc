#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;
bool visited[30];

void INPUT()
{
    IAMFAST
    cin >> str;
}

void solution()
{
    for (auto s : str) visited[s - 'A'] = true;

    bool ans = true;

    string mobis = "MOBIS";
    for (auto s : mobis)
        if (!visited[s - 'A'])
            ans = false;

    (ans) ? (cout << "YES") : (cout << "NO");
}

int main()
{
    INPUT();
    solution();
}