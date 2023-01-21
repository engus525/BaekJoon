#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int V[500001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> V[i];
}


void SOLVE()
{
    int start = 0,end = 0;
    int sum = V[0];

    int ans = 0;
    while(end < n)
    {
        if(sum <= m)
        {
            ans = max(ans,sum);
            sum += V[++end];
        }
        else
        {
            if(start == end)
            {
                start++;
                end++;
                sum = V[start];
            }
            else sum -= V[start++];
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}