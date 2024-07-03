#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string str;
bool visited[30];

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    while (n--)
    {
        memset(visited, false, sizeof visited);
        int ans = 2015;
        cin >> str;
        for (auto s : str)
        {
            if (visited[s - 'A']) continue;
            visited[s - 'A'] = true;
            ans -= s;
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}