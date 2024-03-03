#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
stack<pii> st;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void DO()
{
    if (st.empty()) return;

    st.top().second--;
    if (st.top().second == 0)
        ans += st.top().first, st.pop();
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        int bin, a, t;
        cin >> bin;
        if (bin == 0)
        {
            DO();
            continue;
        }

        cin >> a >> t;
        st.emplace(a, t);

        DO();

    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}