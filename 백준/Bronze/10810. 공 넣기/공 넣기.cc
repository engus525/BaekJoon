#include <iostream>
#include <algorithm>

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
    while(m--)
    {
        int s,e,k; cin>>s>>e>>k;
        for(int i = s; i <= e; i++) li[i] = k;
    }
    for(int i = 1; i <= n; i++) cout << li[i] << " ";

}

int main()
{
    INPUT();
    SOLVE();
}