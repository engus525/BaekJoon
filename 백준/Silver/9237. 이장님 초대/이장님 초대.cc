#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> tree;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int day; cin >> day;
        tree.push_back(day);
    }
}

void SOLVE()
{
    sort(tree.rbegin(), tree.rend());

    int ans = 0;
    for(int i = 0; i < tree.size(); i++)
        ans = max(ans, tree[i] + i + 2);

    cout << ans;
}

int main()
{

    INPUT();
    SOLVE();
}
