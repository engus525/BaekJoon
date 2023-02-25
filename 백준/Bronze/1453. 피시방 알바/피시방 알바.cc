#include <iostream>
#include <string>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

bool visited[101];

void INPUT()
{
    IAMFAST
    cin >> n;
}


void SOLVE()
{
    int ans = 0;
    while(n--)
    {
        int num; cin >> num;
        if(visited[num]) ans++;
        else visited[num] = true;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}