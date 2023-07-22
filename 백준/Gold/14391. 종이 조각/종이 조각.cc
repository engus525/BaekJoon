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
int graph[5][5];
int ans = 0;

void INPUT()
{
    //IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &graph[i][j]);
}

void solution()
{
    for(int bit = 0; bit < (1 << (n*m)); bit++)
    {
        int score = 0;

        //row
        for(int i = 0; i < n; i++)
        {
            int temp = 0;
            for (int j = 0; j < m; j++)
            {
                int idx = i * m + j;

                if((bit & (1 << idx)) == 0) temp = temp * 10 + graph[i][j];
                else score += temp, temp = 0;
            }
            score += temp;
        }

        //col
        for(int i = 0; i < m; i++)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                int idx = j * m + i;

                if((bit & (1 << idx))) temp = temp * 10 + graph[j][i];
                else score += temp, temp = 0;
            }
            score += temp;
        }

        //set ans
        ans = max(ans, score);
    }

    cout << ans;
}

int main()
{
    INPUT();
    solution();
}