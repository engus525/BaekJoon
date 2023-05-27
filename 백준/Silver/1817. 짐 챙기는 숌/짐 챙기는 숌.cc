#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int book[51];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> book[i];
}

void SOLVE()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans++;
        int total = 0;
        while(true)
        {
            if(total+book[i] <= m && i < n) total += book[i++];
            else
            {
                i--;
                break;
            }
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}