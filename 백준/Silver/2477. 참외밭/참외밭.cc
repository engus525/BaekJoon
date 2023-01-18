#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int k;
vector<pair<int,int>> dir;
int cnt[5]{0,};
int total = 1, part = 1;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k;
    for(int i = 0; i < 6; i++)
    {
        int d, len; cin >> d >> len;
        dir.push_back({d,len});
        cnt[d]++;
    }
}



void SOLVE()
{

    for(int i = 0; i < 6; i++)
    {

        // 전체 넓이 구하기
        if(cnt[dir[i].first] == 1)
        {
            total *= dir[i].second;
            continue;
        }

        // 손실 넓이 구하기
        if(cnt[dir[i].first] == cnt[dir[(i + 2) % 6].first])
        {// 현재와 다다음의 방향이 같다면, 다음의 길이가 part의 한 변
            part *= dir[(i + 1) % 6].second;
        }
    }

    cout << (total - part) * k;
}

int main()
{
    INPUT();
    SOLVE();
}
