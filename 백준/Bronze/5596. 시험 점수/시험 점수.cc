#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int x,y;
int a=0,b=0;

void INPUT()
{
    IAMFAST
    for(int i = 0; i < 4; i++) cin >> x,a += x;
    for(int i = 0; i < 4; i++) cin >> y,b += y;
}



void SOLVE()
{
    cout << max(a,b);
}

int main()
{
    INPUT();
    SOLVE();
}