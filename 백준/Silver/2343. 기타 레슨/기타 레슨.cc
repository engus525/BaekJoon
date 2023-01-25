#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int li[100001];
int Max = -1;
int total = 0;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> li[i],Max=max(Max,li[i]),total += li[i];
}


void SOLVE()
{

    int left = Max,right = total;
    int ans;

    while(left <= right)
    {
        int mid = (left+right)/2;

        int cnt = 1, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(sum + li[i] <= mid) sum += li[i];
            else sum = li[i],cnt++;
        }

        if(cnt <= m) ans = mid,right = mid - 1;
        else left = mid + 1;
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}