#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, m;
vector<int> v;
vector<int> comb;
bool visited[10001];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (visited[num]) continue;
        visited[num] = true;
        v.emplace_back(num);
    }
}

void setAns()
{
    for (int i = 0; i < m; i++) cout << comb[i] << " ";
    cout << '\n';
}


void setComb(int depth, int start)
{
    if (depth == m)
    {
        setAns();
        return;
    }

    for (int i = start; i < v.size(); i++)
    {
        comb.emplace_back(v[i]);
        setComb(depth + 1, i);
        comb.pop_back();
    }
}

void solution()
{
    sort(v.begin(), v.end());
    setComb(0, 0);
}

int main()
{
    INPUT();
    solution();
}
