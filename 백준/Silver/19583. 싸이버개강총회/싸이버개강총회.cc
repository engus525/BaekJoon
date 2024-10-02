#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

string s, e, q;
unordered_set<string> nameSet;
unordered_map<string, bool> nameMap;

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
        if (t <= s) nameMap.emplace(name, false);
        else if (e <= t && t <= q)
        {
            auto it = nameMap.find(name);
            if (it == nameMap.end()) continue;
            if (nameMap[name]) continue;
            ans++;
            nameMap[name] = true;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}