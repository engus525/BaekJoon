#include <iostream>
using namespace std;

int n, m;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
}

void SOLVE()
{
    if (n == 1) cout << 1;
    else if (n == 2)
    {
        if (m >= 7) cout << 4;
        else cout << (m + 1) / 2;
    }
    else
    {
        if (m <= 3) cout << m;
        else if (m <= 6) cout << 4;
        else cout << (m - 8 + 1) + 5;
    }
}


int main()
{
    INPUT();
    SOLVE();
}

