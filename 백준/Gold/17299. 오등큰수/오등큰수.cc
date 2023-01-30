#include <iostream>
#include <stack>
using namespace std;

int n;
int A[1000001];

stack<int> s;
int cnt[1000001];
int ans[1000001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i] , cnt[A[i]]++;
}


void SOLVE()
{
    for(int i = n-1; i >= 0; i--)
    {
        while(!s.empty() && cnt[s.top()] <= cnt[A[i]]) s.pop();

        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();

        s.push(A[i]);
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
}

int main()
{
    INPUT();
    SOLVE();
}