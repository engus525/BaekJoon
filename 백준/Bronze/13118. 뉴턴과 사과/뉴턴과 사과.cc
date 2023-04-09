#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int li[4];
int x,y,r;

void INPUT()
{
    IAMFAST
    cin >> li[0]  >> li[1]  >> li[2]  >> li[3]  >> x >> y >> r;
}

void SOLVE()
{
    bool is = false;
    for(int i = 0; i < 4; i++)
        if(li[i] == x)
            is = true, cout << i+1;
    if(!is) cout << 0;
}

int main()
{
    INPUT();
    SOLVE();
}