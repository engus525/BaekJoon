#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
vector<int> comb;
bool visited[9];

void INPUT()
{
    IAMFAST
    cin >> n;
}

void setComb(int depth)
{
    if (depth == n)
    {
        for (int i = 0; i < n; i++) cout << comb[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        comb.emplace_back(i);
        setComb(depth + 1);
        visited[i] = false;
        comb.pop_back();
    }
}

void solution()
{
    setComb(0);
}

int main()
{
    INPUT();
    solution();
}
