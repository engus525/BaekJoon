#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
}


void SOLVE()
{

    int left = 0,right = n-1;
    int ans = 0;
    int v = 0;

    while(left < n - 1)
    {
        v = (right - left - 1) * min(a[left],a[right]);
        ans = max(ans,v);

        if(a[left] < a[right]) left++; // 작은쪽을 바꿔보자
        else right--;
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}