#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int m,n;

void INPUT()
{
    IAMFAST
    cin >> m >> n;
}

void SOLVE()
{
    int _sum = 0; int min = -1;
    for(double i = n; i >= m; i--)
    {
        if(int(sqrt(i)) == sqrt(i)) _sum += i,min = i;
    }
    if(_sum) cout << _sum << '\n' << min;
    else cout << min;

}

int main()
{
    INPUT();
    SOLVE();
}