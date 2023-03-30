#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t,n;
int li[100001];
bool visited[100001];
bool ban[100001];

void INPUT()
{
    IAMFAST
    cin >> t;
}

int DFS(int now)
{
    int ret = 0;

    visited[now] = true;

    if(!visited[li[now]]) ret = DFS(li[now]);
    else if(visited[li[now]] && !ban[li[now]])
    {
        ret++;
        for(int i = li[now]; i != now; i = li[i])
            ret++;
    }

    ban[now] = true;
    return ret;
}

void SOLVE()
{
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> li[i],
            visited[i] = false,
            ban[i] = false;

        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(!visited[i]) cnt += DFS(i);
        cout << n - cnt << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}