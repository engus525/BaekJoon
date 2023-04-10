#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int total;
int sum = 0;
int li[9];

void INPUT()
{
    IAMFAST
    cin >> total;
    for(int i = 0; i < 9; i++) cin >> li[i],sum += li[i];
}


void SOLVE()
{
    cout << total-sum;
}

int main()
{
    INPUT();
    SOLVE();
}