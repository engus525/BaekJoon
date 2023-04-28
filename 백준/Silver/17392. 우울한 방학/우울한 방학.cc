#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int H[1001];
//우울한 기간의 합
int sad;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    sad = m;
    for(int i = 0; i < n; i++) cin >> H[i], sad -= H[i]+1;
}

void SOLVE()
{
    int ans = 0;

    int value = 1;
    while(sad > 0)
    {
        if(sad >= n+1) ans += (value*value) * (n+1);
        else ans += (value*value) * sad;

        sad -= n+1;
        value++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}