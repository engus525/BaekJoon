#include <iostream>
#include <algorithm>
using namespace std;

int n,h;
int bottom[500001],top[500001];//list[i] : 높이가 i인 장애물의 갯수
int sum[500001]; //sum[i] : i번 구간으로 날아갈때 파괴할 장애물의 갯수


void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> h;
    for(int i = 0; i < n/2; i++)
    {
        int a,b; cin >> a >> b;
        // h+1-b 이유 : bottom과 index를 맞춰 누적합 계산
        bottom[a]++; top[h + 1 - b]++;
    }
}


void SOLVE()
{
    //높이별 갯수 -> 누적합
    for(int i = 1; i < h; i++)
    {
        bottom[h - i] += bottom[h - i + 1];
        top[i + 1] += top[i];
    }

    int ans = 2e9 , cnt = 0;
    for(int i = 1; i <= h; i++)
    {
        sum[i] = bottom[i] + top[i];

        if(ans > sum[i]) ans = sum[i] , cnt = 1;
        else if(ans == sum[i]) cnt++;
    }

    cout << ans << " " << cnt;
}

int main()
{
    INPUT();
    SOLVE();
}