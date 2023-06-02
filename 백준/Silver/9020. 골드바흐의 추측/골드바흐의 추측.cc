#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t,n;
int notPrime[10001];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void eratos()
{
    notPrime[1] = true;
    for(int i = 2; i*i <= 10000; i++)
        for(int j = 2; i*j <= 10000; j++)
            notPrime[i*j] = true;
}

void SOLVE()
{
    eratos();

    while(t--)
    {
        cin >> n;

        int gap = 2e9, ans1, ans2;
        for(int i = 2; i <= n/2; i++)
        {
            if(!notPrime[i])
                if(!notPrime[n - i])
                    if(gap > abs(i-(n-i)))
                        gap = abs(i-(n-i)),
                        ans1 = i,ans2 = n-i;
        }
        cout << ans1 << " " << ans2 << '\n';

    }
}

int main()
{
    INPUT();
    SOLVE();
}