#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
multiset<string> S;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string name;
        char val;
        cin >> name >> val;

        if (val == '+')
        {
            S.emplace(name);
        } else
        {
            if (S.find(name) == S.end())
            {
//                cout << i + 1 << '\n';
                ans++;
            }
            else
            {
                auto it = S.find(name);
                S.erase(it);
            }
        }

    }
//    cout << "ans : " << ans << '\n';
    cout << ans + S.size();
}

int main()
{
    INPUT();
    solution();
}