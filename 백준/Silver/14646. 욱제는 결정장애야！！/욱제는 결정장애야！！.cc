#include <iostream>
#include <queue>
using namespace std;

int n;
bool visited[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
}


void SOLVE()
{
    int ans = 0; int sticker = 0;
    for(int i = 0; i < 2*n; i++)
    {
        int p; cin >> p;
        if(!visited[p]) visited[p]=true,sticker++;
        else sticker--;
        ans = max(ans,sticker);
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}