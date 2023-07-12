#include <iostream>
#include <stack>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    long long ans = 0;

    stack<pair<int,int>> st;
    while(n--)
    {
        int h; cin >> h;

        while(!st.empty() && st.top().first < h)
            ans += st.top().second,
            st.pop();

        if(st.empty()) st.emplace(h,1);
        else
        {
            if(st.top().first == h)
            {
                int cnt = st.top().second;
                st.pop();

                ans += (!st.empty()) ? cnt+1 : cnt;
                st.emplace(h,cnt+1);
            }
            else
            {
                ans++;
                st.emplace(h,1);
            }
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}