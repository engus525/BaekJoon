#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int m,t,n;
int Time;
string pos;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> ans;
priority_queue<pii,vector<pii>,greater<pii>> L,R;
int now = 0;
int dock = 0;

void INPUT()
{
    IAMFAST
    cin >> m >> t >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> Time >> pos;
        if(pos == "left") L.push({Time,i});
        else R.push({Time,i});
    }
}

void Move(int x)
{
    now = x+t;
    dock = 1 - dock;
}

void LtoR()
{
    for(int i = 0; i < m; i++)
    {
        if(L.empty()) break;
        if(L.top().first > now) break;
        ans.push({L.top().second,now+t});
        L.pop();
    }
    Move(now);
}

void RtoL()
{
    for(int i = 0; i < m; i++)
    {
        if(R.empty()) break;
        if(R.top().first > now) break;
        ans.push({R.top().second,now+t});
        R.pop();
    }
    Move(now);
}


void SOLVE()
{
    while(!L.empty() || !R.empty())
    {
        if(dock == 0)
        {
            if(!L.empty())
            {
                //왼쪽에 기다리는 사람이 있다면
                if(now >= L.top().first)
                {
                    LtoR();
                    continue;
                }
                //왼쪽에 기다리는 사람이 없다면
                else
                {
                    int l = L.top().first;
                    int r = (R.empty()) ? 2e9 : R.top().first;
                    //왼쪽에 먼저 온다면
                    if(l <= r)
                    {
                        now = l;
                        //도착 시간이 l인 사람은 모두 태울 수 있음
                        LtoR();
                        continue;
                    }
                    //오른쪽에 먼저 온다면
                    else
                    {
                        Move(max(now,r));
                        continue;
                    }
                }

            }//if(!L.empty()) end
            else
            {
                Move(max(now,R.top().first));
                continue;
            }
        }//if(dock == 0) end

        else//if(dock == 1)
        {
            if(!R.empty())
            {
                //오른쪽에 기다리는 사람이 있다면
                if(now >= R.top().first)
                {
                    RtoL();
                    continue;
                }
                //오른쪽에 기다리는 사람이 없다면
                else
                {
                    int l = (L.empty()) ? 2e9 : L.top().first;
                    int r = R.top().first;
                    //오른쪽에 먼저 온다면
                    if(l >= r)
                    {
                        now = r;
                        //도착 시간이 r인 사람은 모두 태울 수 있음
                        RtoL();
                        continue;
                    }
                    //왼쪽에 먼저 온다면
                    else
                    {
                        Move(max(now,l));
                        continue;
                    }
                }

            }//if(!R.empty()) end
            else
            {
                Move(max(now,L.top().first));
                continue;
            }
        }
    }

    while(!ans.empty())
    {
        cout << ans.top().second << '\n';
        ans.pop();
    }
}

int main()
{
    INPUT();
    SOLVE();
}