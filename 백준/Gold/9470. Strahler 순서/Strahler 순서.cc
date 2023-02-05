#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
int k,m,p;
int a,b;

typedef pair<int,int> pii;
vector<int> graph[1001];
int inDegree[1001];
pii strahler[1001];//strahler기록 : {진입노드의 순서 중 최댓값,갯수}

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

void Init()
{
    for(int i = 1; i <= m; i++)
        graph[i].clear(),
        inDegree[i] = 0,
        strahler[i] = {0,0};
}

int TP()
{
    queue<pii> q;
    //강의 근원
    for(int i = 1; i <= m; i++)
        if(!inDegree[i])
        {
            q.push({i,1});//노드 순서는 무조건 1
            strahler[i] = {1,1};
        }

    while(!q.empty())
    {
        int now = q.front().first;
        int stra = q.front().second;
        q.pop();

        for(int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];

            //현재 노드의 순서가 다음 노드의 순서보다 크다면 최댓값 갱신
            if(strahler[next].first < stra) strahler[next] = {stra,1};
            //현재 노드의 순서와 다음 노드의 순서가 같다면, 갯수 1 증가
            else if(strahler[next].first == stra) strahler[next].second++;

            if(--inDegree[next] == 0)
            {
                /*
                 * 나머지 노드는 그 노드로 들어오는 강의 순서 중 가장 큰 값을 i라고 했을 때,
                 * 들어오는 모든 강 중에서 Strahler 순서가 i인 강이 1개이면 순서는 i,
                 * 2개 이상이면 순서는 i+1이다.
                 * */
                int order;
                if(strahler[next].second > 1)
                    order = strahler[next].first + 1;
                else order = strahler[next].first;

                q.push({next,order});
            }
        }
    }
    return (strahler[m].second == 1) ? strahler[m].first : strahler[m].first+1;
}

void SOLVE()
{
    while(t--)
    {
        Init();

        //input
        cin >> k >> m >> p;
        for(int i = 0; i < p; i++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            inDegree[b]++;
        }

        cout << k << " " << TP() << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}