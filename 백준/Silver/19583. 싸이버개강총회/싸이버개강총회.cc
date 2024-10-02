#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

string s, e, q;
set<string> nameSet;

void INPUT()
{
    IAMFAST
    cin >> s >> e >> q;
}


void solution()
{

    int ans = 0;

    string t, name;
    while (cin >> t >> name)
    {
        if (t <= s) nameSet.emplace(name);
        else if (e <= t && t <= q)
        {
            auto it = nameSet.find(name);
            if (it == nameSet.end()) continue;
            ans++;
            nameSet.erase(it);
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}