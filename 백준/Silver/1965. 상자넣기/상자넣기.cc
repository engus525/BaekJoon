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
    while (n--)
    {
        int box;
        cin >> box;
        if(v.empty()) v.emplace_back(box);
        else if (v.back() < box) v.emplace_back(box);
        else
        {
            int idx = lower_bound(v.begin(), v.end(), box)
                      - v.begin();
            v[idx] = box;
        }
    }
    cout << v.size();
}

int main()
{
    INPUT();
    SOLVE();
}