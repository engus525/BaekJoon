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
    for(int line = 0; line < n; line++)
    {
        for(int i = 0; i < line; i++) cout << " ";
        for(int i = 0; i < 2*n-1 - 2*line; i++) cout << "*";
        if(line != n-1) cout << '\n';
    }
    for(int line = 1; line < n; line++)
    {
        cout << '\n';
        for(int i = 0; i < n-1-line; i++) cout << " ";
        for(int i = 0; i < 2*line+1; i++) cout << "*";
    }
}

int main()
{
    INPUT();
    SOLVE();
}