#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int li[100001];
int ps[100001];
int q;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> li[i];
        if(li[i-1] > li[i]) ps[i] = ps[i-1]+1;
        else ps[i] = ps[i-1];
    }
    cin >> q;
}


void SOLVE()
{
    while(q--)
    {
        int a,b; cin>>a>>b;

        cout << ps[b]-ps[a] << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}