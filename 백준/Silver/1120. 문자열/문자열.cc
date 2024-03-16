#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    if (a.length() < b.length()) swap(a, b);

    int maxSame = 0;
    for (int i = 0; i <= a.length() - b.length(); i++)
    {
        int cntSame = 0;
        for (int j = 0; j < b.length(); j++)
            if (a[i + j] == b[j]) cntSame++;
        maxSame = max(maxSame, cntSame);
    }

    cout << b.length() - maxSame;
}

int main()
{
    INPUT();
    solution();
}