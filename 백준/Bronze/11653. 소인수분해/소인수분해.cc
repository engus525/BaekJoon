#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int notPrime[10'000'001];
vector<int> prime;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    while (n != 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if(n%i) continue;
            cout << i << '\n';
            n /= i;
            break;
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}