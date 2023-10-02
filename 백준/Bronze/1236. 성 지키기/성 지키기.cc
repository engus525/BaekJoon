#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
char graph[51][51];

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1s", &graph[i][j]);
}


void solution()
{

    int r = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] == 'X')
            {
                r++;
                break;
            }

    int c = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (graph[j][i] == 'X')
            {
                c++;
                break;
            }

    cout << max(n - r, m - c);
}

int main()
{
    INPUT();
    solution();
}