#include <iostream>
#include <stack>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
stack<ll> st;
ll ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    while (n--)
    {
        ll num; cin >> num;

        if (st.empty() || st.top() > num) st.push(num);
        else if (st.top() < num)
        {
            ans += num - st.top(); st.pop();
            while(!st.empty())
            {
                if (st.top() > num) break;
                else st.pop();
            }
            st.push(num);
        }
    }

    while(st.size() > 1)
    {
        ll top = st.top();
        st.pop();
        ans += st.top() - top;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}