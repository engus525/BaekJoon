#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int S;
struct EMOJI
{
    int num;
    int clip;
    int t;
};
bool visited[1201][1201];

void INPUT()
{
    IAMFAST
    cin >> S;
}

void BFS()
{
    queue<EMOJI> q;
    q.push({1,0,0});//{이모티콘 수,시간}

    while(!q.empty())
    {
        int num = q.front().num;
        int clip = q.front().clip;
        int t = q.front().t;
        q.pop();

        if(num == S)
        {
            cout << t;
            return;
        }

        if(!visited[num][num])
            q.push({num,num,t+1}),
            visited[num][num] = true;

        if(num+clip <= 1200 && clip && !visited[num+clip][clip])
            q.push({num+clip, clip, t+1}),
            visited[clip+num][0] = true;

        if(num && !visited[num-1][clip])
            q.push({num-1,clip,t+1}),
            visited[num-1][clip] = true;

    }
    return;
}

void SOLVE()
{
    BFS();
}

int main()
{
    INPUT();
    SOLVE();
}