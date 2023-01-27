#include <iostream>
#include <algorithm>
using namespace std;

int n;
int honey[100001];
int goRight[100001],goLeft[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> honey[i],
        goLeft[i] = goRight[i] = honey[i];
}


void SOLVE()
{

    //prefixSum
    for(int i = 1; i < n; i++)
    {
        goLeft[n - i] += goLeft[n - i + 1];
        goRight[i + 1] += goRight[i];
    }


    int ans = -1;

    int sum;
    //벌 한 마리가 왼쪽 끝에서 출발 -> 꿀통은 가장 오른쪽
    for(int i = 2; i <= n-1; i++)
    {
        sum = 2 * goRight[n] - goRight[i] - (honey[i] + honey[1]);
        ans = max(ans, sum);
    }

    //벌 한 마리가 오른쪽 끝에서 출발 -> 꿀통은 가장 왼쪽
    for(int i = 2; i <= n-1; i++)
    {
        sum = 2 * goLeft[1] - goLeft[i] - (honey[i] + honey[n]);
        ans = max(ans, sum);
    }

    //벌이 양쪽 끝에서 출발 -> 꿀통 위치에 따라 다름
    for(int i = 2; i <= n-1; i++)
    {
        sum = (goRight[i] - honey[1]) + (goLeft[i] - honey[n]);
        ans = max(ans,sum);
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}