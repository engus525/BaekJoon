#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
vector<int> v;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void SOLVE()
{
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if(v.empty() || v[v.size()-1] < a) v.emplace_back(a);
        else
        {
            int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
            v[idx] = a;
        }
    }

    cout << n - v.size();
}

int main()
{
    INPUT();
    SOLVE();
}