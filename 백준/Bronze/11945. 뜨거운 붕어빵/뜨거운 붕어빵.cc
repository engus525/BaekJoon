#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int graph[11][11];

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%1d", &graph[i][j]);
}


void solution()
{
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << graph[i][m - 1 - j];
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}