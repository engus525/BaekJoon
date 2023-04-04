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

void eratos()
{
    notPrime[1] = true;
    for(int i = 2; i*i <= n; i++)
        for(int j = i*i; j <= n; j += i)
            notPrime[j] = true;
}

void SOLVE()
{
    eratos();
    for(int i = 2; i <= n; i++)
        if(!notPrime[i]) prime.push_back(i);

    while(n)
    {
        if(n == 1) break;
        for(auto i : prime)
        {
            if(n%i == 0)
            {
                cout << i << '\n';
                n /= i;
                break;
            }
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}