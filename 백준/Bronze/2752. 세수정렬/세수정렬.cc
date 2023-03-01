#include <iostream>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int list[3];

void INPUT()
{
    IAMFAST
    for(int i = 0; i < 3; i++) cin >> list[i];
}

void SOLVE()
{
    sort(list,list+3);
    for(int i = 0; i < 3; i++) cout << list[i] << " ";
}

int main()
{
    INPUT();
    SOLVE();
}