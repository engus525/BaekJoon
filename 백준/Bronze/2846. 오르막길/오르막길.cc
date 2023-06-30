#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int P[1001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> P[i];
}



void SOLVE()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int left = P[i];
        int right = P[i];
        while(P[i+1] > P[i])
        {
            i++;
            if(i >= n) break;
            right = P[i];
        }

        ans = max(ans, right-left);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}