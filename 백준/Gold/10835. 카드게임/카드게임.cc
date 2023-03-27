#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int L[2001],R[2001];
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> L[i];
    for(int i = 0; i < n; i++) cin >> R[i];
}

int DFS(int lidx,int ridx,int score)
{
    if(lidx==n || ridx==n) return ans = max(ans,score);

    DFS(lidx+1,ridx,score);
    DFS(lidx+1,ridx+1,score);
    if(L[lidx] > R[ridx]) DFS(lidx,ridx+1,score+R[ridx]);
    return ans = max(ans,score);
}


void SOLVE()
{
    cout << DFS(0,0,0);
}

int main()
{
    INPUT();
    SOLVE();
}