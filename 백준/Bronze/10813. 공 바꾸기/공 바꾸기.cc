#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int li[101];

void INPUT()
{
    IAMFAST
    cin >> n >> m;
}

void SOLVE()
{
    for(int i = 1; i <= n; i++) li[i] = i;

    while(m--)
    {
        int a,b; cin>>a>>b;

        int temp = li[a];
        li[a] = li[b];
        li[b] = temp;
    }
    for(int i = 1; i <= n; i++) cout << li[i] << " ";
}

int main()
{
    INPUT();
    SOLVE();
}