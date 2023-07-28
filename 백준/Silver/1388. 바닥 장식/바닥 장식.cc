#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
char graph[51][51];
bool visited[51][51];

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%1s", &graph[i][j]);
}

void solution()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (visited[i][j]) continue;

            ans++;
            if (graph[i][j] == '-')
            {
                int col = j;
                while (col < m && graph[i][col] == '-')
                    visited[i][col++] = true;
            }
            else if (graph[i][j] == '|')
            {
                int row = i;
                while (row < n && graph[row][j] == '|')
                    visited[row++][j] = true;
            }
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}