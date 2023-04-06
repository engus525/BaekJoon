#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int li[5];
int ave = 0;

void INPUT()
{
    IAMFAST
    for(int i = 0; i < 5; i++) cin >> li[i], ave += li[i];
}

void SOLVE()
{
    sort(li,li+5);
    cout << ave/5 << '\n' << li[2];
}

int main()
{
    INPUT();
    SOLVE();
}