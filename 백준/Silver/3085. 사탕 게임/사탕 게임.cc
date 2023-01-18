#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
char map[51][51];

void INPUT()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%1s", &map[i][j]);
}

int candy()
{
    int score = 1;

    for(int i = 0; i < n; i++)
    {
        int temp = 1;
        // check row
        for(int j = 1; j < n; j++)
        {
            if(map[i][j] == map[i][j - 1])
            {
                score = max(score, temp + 1);
                temp++;
            }
            else temp = 1;
        }

        // check col
        temp = 1;
        for(int j = 1; j < n; j++)
        {
            if(map[j][i] == map[j - 1][i])
            {
                score = max(score, temp + 1);
                temp++;
            }
            else temp = 1;
        }
    }
    return score;
}

void SOLVE()
{
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char temp;
            // swap row
            if(j < n - 1)
            {
                temp = map[i][j];
                map[i][j] = map[i][j + 1];
                map[i][j + 1] = temp;

                ans = max(ans, candy());

                temp = map[i][j + 1];
                map[i][j + 1] = map[i][j];
                map[i][j] = temp;
            }
            // swap col
            if(i < n - 1)
            {
                temp = map[i][j];
                map[i][j] = map[i + 1][j];
                map[i + 1][j] = temp;

                ans = max(ans, candy());

                temp = map[i + 1][j];
                map[i + 1][j] = map[i][j];
                map[i][j] = temp;
            }
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
