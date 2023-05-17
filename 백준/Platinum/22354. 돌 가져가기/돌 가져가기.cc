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
        if (str[i-1] == 'B' && str[i] == 'W')
        {
            int idx = i;
            while(true)
            {
                if(idx == n) break;
                if(str[idx] == 'B')
                {
                    candidate = true;
                    i = idx-1;
                    break;
                }
                pq.push(A[idx++]);
            }
        }
        else if (str[i-1] == 'W' && str[i] == 'B')
        {
            int idx = i;
            while(true)
            {
                if(idx == n) break;
                if(str[idx] == 'W')
                {
                    candidate = true;
                    i = idx-1;
                    break;
                }
                pq.push(A[idx++]);
            }
        }
//        if(candidate) cout << pq.top() << " ";
        if(candidate) score.push(pq.top());
    }

    ll ans = 0;
    int cnt = score.size();
    for (int i = 0; i < cnt; i++) ans += score.top(), score.pop(), cnt--;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}