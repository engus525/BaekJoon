#include <iostream>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int ana[200001];
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> ana[i];
}

void SOLVE()
{
    int MIN = ana[1];
    for(int i = 2; i <= n; i++)
    {
        MIN = (MIN > ana[i]) ? ana[i] : MIN;
        ans = max(ans,ana[i]-MIN);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}