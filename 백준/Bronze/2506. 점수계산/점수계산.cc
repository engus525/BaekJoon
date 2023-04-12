#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int li[101];
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> li[i];
        if(li[i-1] && li[i]) li[i] = li[i-1]+1;
        else if(li[i]) li[i] = 1;
        ans += li[i];
    }
}

void SOLVE()
{
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}