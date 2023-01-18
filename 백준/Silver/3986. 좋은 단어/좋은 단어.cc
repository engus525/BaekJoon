#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
string ab;

int ans = 0;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}


void SOLVE()
{
    while(n--)
    {
        stack<char> st;
        cin >> ab;
        for(int i = 0; i < ab.length(); i++)
        {
            if(ab[i] == 'A')
            {
                if(!st.empty() && st.top() == 'A') st.pop();
                else st.push('A');
            }
            else
            {
                if(!st.empty() && st.top() == 'B') st.pop();
                else st.push('B');
            }
        }

        if(st.empty()) ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}