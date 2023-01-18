#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int numList[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> numList[i];
}


void SOLVE()
{
    int start = 0,end = 0;
    int sum = numList[0];

    int ans = 2e9;
    while(end < n)
    {
        if(sum >= m)
        {
            if(start == end)
            {
                cout << 1;
                exit(0);
            }
            ans = min(ans,end - start + 1);
            sum -= numList[start++];
        }
        else
        {
            sum += numList[++end];
        }
    }

    if(ans != 2e9) cout << ans;
    else cout << 0;
}

int main()
{
    INPUT();
    SOLVE();
}