#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k;
int card[1001];
bool visited[1001];

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for(int i = 0; i < n*k; i++) cin >> card[i];
}


void SOLVE()
{
    int cnt = 0;//제거한 카드 수

    int idx = 0;//선택된 카드
    while(cnt != n*k-1)//한 장만 남을 때까지
    {
        int move = card[idx];
        cnt++;
        visited[idx] = true;
        for(int i = 1; i <= move; i++)
            if(visited[(idx+i)%(n*k)]) move++;
        idx = (idx+move)%(n*k);
    }
    cout << (idx)/k + 1 << " " << card[idx];
}

int main()
{
    INPUT();
    SOLVE();
}