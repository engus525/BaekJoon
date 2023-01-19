#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int n,d,k,c;
int belt[30001];
int visited[3001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>d>>k>>c;
    for(int i = 0; i < n; i++) cin >> belt[i];
}


void SOLVE()
{
    int ans = 0; bool coupon = false;
    // Init
    for(int i = 0; i < k; i++)
    {
        if(!visited[belt[i]]) ans++;
        visited[belt[i]]++;
    }
    if(!visited[c]) coupon=true,ans++;

    int Max = ans;
    int left = 0, right = k-1;
    for(int i = 0; i < n-1; i++)
    {
        // 가장 왼쪽에 있던 초밥은 먹지 않게됨
        visited[belt[left]]--;
        // 빠진 초밥 종류의 수가 0이 된다면 가짓수 -1
        if(!visited[belt[left]]) ans--;

        // move pointer
        left++; left%=n;
        right++; right%=n;

        // 새로운 종류를 먹는다면
        if(!visited[belt[right]]) ans++;
        // 갯수 갱신
        visited[belt[right]]++;

        // 쿠폰이 포함되어있지않다면
        if(!visited[c] && !coupon) coupon=true,ans++;

        Max = max(Max,ans);
        // 쿠폰 사용했으면 가짓수 갱신
        if(coupon) ans--,coupon=false;
    }
    cout << Max;
}

int main()
{
    INPUT();
    SOLVE();
}