#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
int n;
string str;
ll A[300001];

void INPUT()
{
    IAMFAST
    cin >> n >> str;
    for (int i = 0; i < n; i++) cin >> A[i];
}

void SOLVE()
{
    priority_queue<ll> score;
    for (int i = 1; i <= n - 2; i++)
    {
        priority_queue<ll> pq;
        bool candidate = false;
        char now = str[i];
        if (str[i-1] != now)
        {
            int idx = i;
            while(idx != n)
            {
                if(str[idx] != now)
                {
                    candidate = true;
                    i = idx-1;
                    break;
                }
                pq.push(A[idx++]);
            }
        }
        if(candidate) score.push(pq.top());
    }

    ll ans = 0;
    int cnt = score.size();
    for (int i = 0; i < (cnt+1)/2; i++) ans += score.top(), score.pop();
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}