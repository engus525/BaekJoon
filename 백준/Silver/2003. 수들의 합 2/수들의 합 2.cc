#include <iostream>
using namespace std;

int n,m;
int numList[10001];

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

    int ans = 0;
    while(end < n)
    {
        if(sum == m) ans++;
        
        if(sum <= m)
        {
            sum += numList[++end];
        }
        else
        {
            if(start == end)
            {
                start++;
                end++;
                sum = numList[start];
            }
            else sum -= numList[start++];
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}