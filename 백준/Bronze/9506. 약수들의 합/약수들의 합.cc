#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
    IAMFAST
}

void SOLVE()
{
    while(cin >> n)
    {
        if(n==-1) break;

        vector<int> v; int s = 0;
        for(int i = 1; i <= n/2; i++)
        {
            if(n%i) continue;
            v.emplace_back(i);
            s += i;
        }

        if(n == s)
        {
            cout << n << " = ";
            for(int i = 0; i < v.size()-1; i++)
                cout << v[i] << " + ";
            cout << v[v.size()-1] << '\n';
        }
        else cout << n << " is NOT perfect.\n";

    }
}

int main()
{
    INPUT();
    SOLVE();
}