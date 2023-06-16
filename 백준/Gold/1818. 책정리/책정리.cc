#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

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
        int book; cin >> book;
        if(v.empty()) v.emplace_back(book);
        else if(v.back() < book) v.emplace_back(book);
        else
        {
            int idx = lower_bound(v.begin(), v.end(), book) - v.begin();
            v[idx] = book;
        }
    }

    cout << n - v.size();
}

int main()
{
    INPUT();
    SOLVE();
}