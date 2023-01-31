#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int l,Ml,Mk,c;
int z;

queue<int> q;
//데미지 누적합 : 기관총 누적O , 지뢰 누적X
int damage[3000001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l >> Ml >> Mk >> c;
    for(int i = 0; i < l; i++) cin >> z , q.push(z);
}


void SOLVE()
{
    int idx = 1; damage[1] = Mk;
    while(!q.empty())
    {
        int D = damage[idx] - damage[max(0,idx-Ml)];
        //맨 앞의 좀비가 기관총으로 죽는다면
        if(q.front() <= D)
        {
            q.pop();
            damage[idx + 1] = damage[idx] + Mk;
            idx++;
        }
        //맨 앞의 좀비가 기관총으로 죽지 않는다면
        else
        {
            //지뢰가 남았다면
            if(c--)
            {
                q.pop();
                damage[idx + 1] = damage[idx];
                idx++;
            }
            else cout << "NO" , exit(0);
        }
    }

    cout << "YES";
}

int main()
{
    INPUT();
    SOLVE();
}