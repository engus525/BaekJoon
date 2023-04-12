#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    int ans = 0;
    while(n--)
    {
        int a,b,c; cin>>a>>b>>c;
        if(a==b && b==c) ans = max(ans,10000+a*1000);
        else if(a==b || b==c || c==a)
        {
            if(a==b || b==c)
                ans = max(ans,1000+b*100);
            else ans = max(ans,1000+a*100);
        }
        else ans = max(ans,100*max(max(a,b),c));
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}