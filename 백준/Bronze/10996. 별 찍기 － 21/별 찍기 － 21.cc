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
    for(int line = 0; line < 2*n; line++)
    {
        for(int i = 0; i < n; i++)
        {
            if(line%2==0)
            {
                if (i % 2 == 0) cout << "*";
                else cout << " ";
            }
            else
            {
                if (i % 2 == 0) cout << " ";
                else cout << "*";
            }
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}