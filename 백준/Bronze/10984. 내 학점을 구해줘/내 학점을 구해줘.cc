#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int t,n,c;
double g;

void INPUT()
{
    IAMFAST
    cin >> t;
}


void SOLVE()
{
    while(t--)
    {
        cin >> n;

        int cSum = 0;
        double total = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> c >> g;
            cSum += c;
            total += c * g;
        }
        cout << fixed; cout.precision(1);
        cout << cSum << " " << total / cSum << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}