#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int m;
bool cup[4];

void INPUT()
{
    IAMFAST
    cin >> m;
}

void SOLVE()
{
    cup[1] = true;
    while(m--)
    {
        int a,b; cin>>a>>b;
        bool temp = cup[a];
        cup[a] = cup[b];
        cup[b] = temp;
    }
    for(int i = 1; i <= 3; i++)
        if(cup[i]) cout << i;
}

int main()
{
    INPUT();
    SOLVE();
}