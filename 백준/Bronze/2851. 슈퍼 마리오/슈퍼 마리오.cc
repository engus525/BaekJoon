#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void INPUT()
{
    IAMFAST
}


void SOLVE()
{
    int ans = 0,sum = 0;
    for(int _ = 0; _ < 10; _++)
    {
        int n; cin >> n;
        sum += n;
        if(abs(100-sum) <= abs(100-ans)) ans = sum;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}