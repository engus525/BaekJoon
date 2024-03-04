#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;

void INPUT()
{
    IAMFAST
}


void solution()
{
    int cnt = 1;
    while (cin >> str)
    {
        if (str[0] == '-') break;

        int ans = 0;
        stack<char> st;
        for (int i = 0; i < str.length(); i++)
        {
            char s = str[i];
            if (!st.empty() && s == '}')
            {
                st.pop();
                continue;
            }

            if (st.empty())
            {
                if (s == '}') ans++;
                st.emplace('{');
                continue;
            }
            else st.emplace(s);
        }
        cout << cnt++ << ". " << ans + st.size() / 2 << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}