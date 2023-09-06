#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
vector<int> v;
vector<int> comb;
set<vector<int>> S;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        v.emplace_back(num);
    }
}


void setComb(int depth)
{
    if (depth == m)
    {
        S.insert(comb);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        comb.emplace_back(v[i]);
        setComb(depth + 1);
        comb.pop_back();
    }
}

void solution()
{
    sort(v.begin(), v.end());
    setComb(0);
    for (auto &s : S)
    {
        for (auto &i: s)
            cout << i << " ";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}
