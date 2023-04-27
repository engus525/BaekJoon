#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int L[21], J[21];
bool visited[21];
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> L[i];
    for(int i = 0; i < n; i++) cin >> J[i];
}

void setAns()
{
    int temp = 0;
    for(int i = 0; i <= n; i++)
        if(visited[i])
            temp += J[i];
    ans = max(ans,temp);
}

void setComb(int now, int target, int start, int stamina)
{
    if(now == target)
    {
        setAns();
        return;
    }

    for(int i = start; i <= n; i++)
    {
        int nextStamina = stamina - L[i];
        if(nextStamina <= 0) continue;

        visited[i] = true;
        setComb(now+1,target,i+1,nextStamina);
        visited[i] = false;
    }
}

void SOLVE()
{
    for(int i = 1; i <= n; i++)
        setComb(0,i,0,100);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
