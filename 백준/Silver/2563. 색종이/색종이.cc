#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
bool graph[101][101];

void INPUT()
{
    IAMFAST
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                graph[a + i][b + j] = true;
    }
}


void solution()
{
    int ans = 0;
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            if (graph[i][j]) ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}