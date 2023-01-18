#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[2];
int n;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}

void SOLVE()
{
    while(n--)
    {
        int vote;
        cin >> vote;
        cnt[vote]++;
    }

    if(cnt[0] < cnt[1])
        cout << "Junhee is cute!";
    else cout << "Junhee is not cute!";
}

int main()
{
    INPUT();
    SOLVE();
}
