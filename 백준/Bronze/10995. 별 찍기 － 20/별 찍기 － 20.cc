#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    for(int i = 0; i < n; i++)
    {
        if(i%2) cout << " ";
        for(int j = 0; j < n; j++) cout << "* ";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}