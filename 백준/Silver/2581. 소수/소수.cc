#include <iostream>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int m,n;
bool prime[10001];

void INPUT()
{
    IAMFAST
    cin >> m >> n;
}

void SOLVE()
{
    memset(prime,true,sizeof prime);
    prime[1] = false;

    for(int i = 2; i*i <= n; i++)
    {
        if(!prime[i]) continue;

        for(int j = i*i; j <= n; j += i)
            prime[j] = false;
    }

    int sum = 0;
    int first = -1;

    for(int i = m; i <= n; i++)
    {
        if(!prime[i]) continue;
        sum += i;
        if(first == -1) first = i;
    }
    if(sum) cout << sum << '\n' << first;
    else cout << -1;

}

int main()
{
    INPUT();
    SOLVE();
}