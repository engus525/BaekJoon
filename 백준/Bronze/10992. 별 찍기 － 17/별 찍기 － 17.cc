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
    for(int _ = 0; _ < n-1; _++) cout << " ";
    cout << "*\n";
    for(int line = 0; line < n-2; line++)
    {
        for(int _ = 0; _ < n-2-line; _++) cout << " ";
        cout << "*";
        for(int _ = 0; _ < 2*line+1; _++) cout << " ";
        cout << "*\n";
    }
    for(int _ = 0; _ < 2*n-1 && n!=1; _++) cout << "*";
}

int main()
{
    INPUT();
    SOLVE();
}