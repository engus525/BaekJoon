#include <iostream>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t,k;
int trinum[1000];

void INPUT()
{
    IAMFAST
    cin >> t;
}

bool canExpress()
{
    for(int i = 1; i < 45; i++)
        for(int j = 1; j < 45; j++)
            for(int x = 1; x < 45; x++)
                    if(trinum[i]+trinum[j]+trinum[x] == k)
                        return true;
    return false;
}

void SOLVE()
{
    for(int i = 1; i <= 50; i++) trinum[i] = trinum[i-1] + i;

    while(t--)
    {
        cin >> k;

        if(canExpress()) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

}

int main()
{
    INPUT();
    SOLVE();
}