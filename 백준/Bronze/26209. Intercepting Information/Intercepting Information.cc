#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int bit;

void INPUT()
{
    IAMFAST
}


void SOLVE()
{
    bool S = true;
    for(int i = 0; i < 8; i++)
    {
        cin >> bit;
        if(bit == 9) S = false;
    }
    if(S) cout << "S";
    else cout << "F";
}

int main()
{
    INPUT();
    SOLVE();
}