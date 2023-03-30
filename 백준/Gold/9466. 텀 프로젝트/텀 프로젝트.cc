#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t,n;
int li[100001];
bool visited[100001];
bool ban[100001];
int cnt = 0;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void DFS(int now)
{
    visited[now] = true;

    if(!visited[li[now]]) DFS(li[now]);
    else if(visited[li[now]] && !ban[li[now]])
    {
        cnt++;
        for(int i = li[now]; i != now; i = li[i])
            cnt++;
    }

    ban[now] = true;
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

        cnt = 0;
        for(int i = 1; i <= n; i++)
            if(!visited[i]) DFS(i);
        cout << n - cnt << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}