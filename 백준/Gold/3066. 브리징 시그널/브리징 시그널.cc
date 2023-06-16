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
    while(t--)
    {
        cin >> n;

        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int port; cin >> port;

            if(v.empty() || v.back() < port) v.emplace_back(port);
            else
            {
                int idx = lower_bound(v.begin(),v.end(),port) - v.begin();
                v[idx] = port;
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