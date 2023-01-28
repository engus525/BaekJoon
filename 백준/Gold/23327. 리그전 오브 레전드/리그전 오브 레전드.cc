#include <iostream>
using namespace std;

typedef long long ll;
int n,q;
ll li[100001];
ll prefixSum[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> li[i] , li[i] += li[i-1];
}


void SOLVE()
{
    //누적 합 구하기
    for(int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i-1] + li[i-1]*(li[i]-li[i-1]);


    while(q--)
    {
        int l,r; cin >> l >> r;
        cout << prefixSum[r] - prefixSum[l-1] - li[l-1]*(li[r]-li[l-1]) << '\n';
    }

}

int main()
{
    INPUT();
    SOLVE();
}