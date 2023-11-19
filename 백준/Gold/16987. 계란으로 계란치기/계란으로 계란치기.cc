#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<pii> v;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, w;
        cin >> s >> w;
        v.emplace_back(s, w);
    }
}

void setComb(int depth, int tempAns)
{
//    cout << "ans : " << tempAns << '\n';
    ans = max(ans, tempAns);

    for (int i = depth; i < n; i++)
    {
        if (v[i].first <= 0) depth++;
        else break;
    }

    if (depth >= n) return;
    auto &[s1, w1] = v[depth];

    for (int i = 0; i < n; i++)
    {
        if (i == depth) continue;

        auto &[s2, w2] = v[i];
        if (s2 <= 0) continue;
        s1 -= w2, s2 -= w1;
//        cout << depth << " hit " << i << '\n';
//        cout << s1 << " " << s2 << '\n';

        if (s1 <= 0 && s2 <= 0) setComb(depth + 1, tempAns + 2);
        else if (s1 <= 0 || s2 <= 0) setComb(depth + 1, tempAns + 1);
        else setComb(depth + 1, tempAns);

        s1 += w2, s2 += w1;
    }
}

void solution()
{
    setComb(0, 0);
    cout << ans;
}


int main()
{
    INPUT();
    solution();
}