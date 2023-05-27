#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int li[51+5];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> li[i];
}

void SOLVE()
{
    sort(li,li+n);

    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        int cnt = 1;
        for(int j = i+1; j < i+5; j++)
            if(li[j]-li[i] < 5 && li[j]) cnt++;
        ans = max(ans,cnt);
    }
    if(ans >= 5) cout << 0;
    else cout << 5-ans;
}

int main()
{
    INPUT();
    SOLVE();
}