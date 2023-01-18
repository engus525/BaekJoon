#include <iostream>
#include <algorithm>
using namespace std;

int n;
int sol[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> sol[i];
}


void SOLVE()
{
    sort(sol, sol + n);

    int ans1 = 0, ans2 = 0;

    int left = 0,right = n-1, sum = sol[0] + sol[n-1];

    int minGap = 2e9;
    while(left < right)
    {
        //cout << left << " " << right << " : " << sum << '\n';
        if(abs(sum) < minGap)
        {
            ans1 = sol[left]; ans2 = sol[right];
            minGap = abs(sum);
        }

        if(sum <= 0)
        {
            if(sum == 0)
            {
                ans1 = sol[left];
                ans2 = sol[right];
                break;
            }
            sum = sol[++left] + sol[right];
        }
        else
        {
            sum = sol[left] + sol[--right];
        }
    }

    cout << ans1 << " " << ans2;
}

int main()
{
    INPUT();
    SOLVE();
}