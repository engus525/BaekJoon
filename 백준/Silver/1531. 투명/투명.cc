#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int graph[101][101];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int x = a; x <= c; x++)
            for (int y = b; y <= d; y++)
                graph[x][y]++;
    }
}


void solution()
{
    int ans = 0;
    for (int x = 1; x <= 100; x++)
        for (int y = 1; y <= 100; y++)
            if (graph[x][y] > m) ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}