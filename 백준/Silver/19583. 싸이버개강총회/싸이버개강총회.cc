#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

string s, e, q;
int sh, sm, eh, em, qh, qm;
set<string> nameSet;

void INPUT()
{
    IAMFAST
    cin >> s >> e >> q;
}

bool beforeS(string t)
{
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return ((h < sh) || (h == sh && m <= sm));
}

bool betweenEQ(string t)
{
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return ((eh < h) || (eh == h && em <= m)) && ((h < qh) || (h == qh && m <= qm));
}

void solution()
{
    sh = stoi(s.substr(0, 2));
    sm = stoi(s.substr(3, 2));
    eh = stoi(e.substr(0, 2));
    em = stoi(e.substr(3, 2));
    qh = stoi(q.substr(0, 2));
    qm = stoi(q.substr(3, 2));

    int ans = 0;

    string t, name;
    while (cin >> t >> name)
    {
        if (beforeS(t)) nameSet.emplace(name);
        else if (betweenEQ(t))
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