#include <iostream>
#include <string>
#include <algorithm>

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
    for(int line = 0; line < n; line++)
    {
        for(int i = 0; i < n-1-line; i++) cout << " ";
        for(int i = 0; i < 2*line+1; i++)
        {
            if(i%2) cout << " ";
            else cout << "*";
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}