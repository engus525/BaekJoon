#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int map[5][4];
int rowSum[5];
pair<int,int> ans = {1,-1};

void INPUT()
{
    IAMFAST
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j];
            rowSum[i] += map[i][j];
        }
        if(rowSum[i] > ans.second) ans = {i+1,rowSum[i]};
    }
}

void SOLVE()
{
    cout << ans.first << " " << ans.second;
}

int main()
{
    INPUT();
    SOLVE();
}