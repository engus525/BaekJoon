#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<pii> v;
stack<pii> st;
int maxH = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
}

void solution()
{
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && v[i].second > st.top().second)
        {
            if (v[i].second > maxH)
            {
                while (st.top().second != maxH)
                    st.pop();
            }
            else while (st.top().second < v[i].second)
                st.pop();
        }

        maxH = max(maxH, v[i].second);
        st.push(v[i]);
    }

    int ans = 0;
    while (!st.empty())
    {
        auto [w, h] = st.top();
        st.pop();

        ans += h;
        if (st.empty()) break;

        if (h < st.top().second)
            ans += (w - st.top().first - 1) * h;
        else
            ans += (w - st.top().first - 1) * st.top().second;
    }

    cout << ans;
}

int main()
{
    INPUT();
    solution();
}