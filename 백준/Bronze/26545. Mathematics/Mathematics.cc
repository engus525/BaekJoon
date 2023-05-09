#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        ans += num;
    }
}


void SOLVE()
{
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}