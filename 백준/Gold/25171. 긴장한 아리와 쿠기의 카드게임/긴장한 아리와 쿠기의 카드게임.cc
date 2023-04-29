#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
ll n,x,y;
ll card[501];
bool visited[501];
ll attack, stamina;
ll ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++) cin >> card[i];
}


void setSecond(int s,int e)
{
    /*
     * two pointer : 체력이 반드시 (팀의 공격 횟수*몬스터 공격력)보다 커야함
     */
    ll minStamina = (y%attack) ? x*((y/attack)+1) : x*(y/attack);

    stamina = 0;
    int left = (s == 0) ? e+1 : 0;
    for (int right = left; right < n; right++)
    {
        if(right == s)
        {
            right = e;
            continue;
        }

        stamina += card[right];
        while(stamina > minStamina)
        {
            if(right < s) ans += n-right-(e-s+1);
            else ans += n-right;

            stamina -= card[left];
            left++;
            if(left == s) left = e+1;
        }
    }
}

void setFirst(int range)
{
    for(int i = 0; i <= n-range; i++)
    {
        //아리 카드 뽑기
        attack = 0;
        for (int j = 0; j < range; j++)
            attack += card[i+j];

        //쿠기 카드 뽑기
        setSecond(i,i+range-1);
    }
}

void SOLVE()
{
    for(int i = 1; i < n; i++) setFirst(i);
    if (ans) cout << ans;
    else cout << "IMPOSSIBLE";
}

int main()
{
    INPUT();
    SOLVE();
}