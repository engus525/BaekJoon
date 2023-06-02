#include <iostream>

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
    for(int i = 2; i*i <= 10000; i++)
    {
        if(notPrime[i]) continue;
        for (int j = i*i; j <= 10000; j+=i)
            notPrime[j] = true;
    }
}

void SOLVE()
{
    eratos();

    while(t--)
    {
        cin >> n;

        pair<int,int> ans = {0,0};
        for(int i = n/2; i >= 2; i--)
        {
            if(!notPrime[i])
                if(!notPrime[n - i])
                {
                    ans = {i,n-i};
                    break;
                }
        }
        cout << ans.first << " " << ans.second << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}