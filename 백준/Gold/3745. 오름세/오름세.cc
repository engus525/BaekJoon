#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int t,n;

void INPUT()
{
    IAMFAST
    cin >> t;
}


void SOLVE()
{
    while(cin >> n)
    {

        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int stock; cin >> stock;

            if(v.empty() || v.back() < stock) v.emplace_back(stock);
            else
            {
                int idx = lower_bound(v.begin(),v.end(),stock) - v.begin();
                v[idx] = stock;
            }
        }

        cout << v.size() << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}