#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> pii;
int n,m,d;
int gameMap[17][16], originMap[17][16];
bool archerPos[17][16];
bool visited[17][16];
vector<pii> archer;
set<pii> removed;
// D가 같으면 가장 왼쪽에 있는 적부터 공격 -> (좌 상 우) 순으로 BFS 진행
int dir[3][2] = {{0,-1},{-1,0},{0,1}};

int ans = 0;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> originMap[i][j];
}

void copyMap()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            gameMap[i][j] = originMap[i][j];
}

bool gameFinished()
{// 적이 하나도 없으면 true 반환
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(gameMap[i][j] == 1)
                return false;
    return true;
}

void enemyMove()
{// 적이 아래로 한 칸씩 이동

    // 제거된 적 0으로 표기
    for(set<pii>::iterator it = removed.begin(); it != removed.end(); it++)
        gameMap[it->first][it->second] = 0;
    removed.clear();

    // 가장 아랫 행부터 이동해야함에 주의한다.
    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
        {
            if(gameMap[i][j] == 1)
            {
                // 적이 성이 있는 칸으로 이동하면 제외
                if(i != n - 1) gameMap[i + 1][j] = 1;
                gameMap[i][j] = 0;
            }
        }
}

void BFS(pii arch)
{// 활 쏘기

    queue<pii> q;
    q.push(arch);
    visited[arch.first][arch.second] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 3; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {// Check range
                if(!visited[nx][ny])
                {
                    if(gameMap[nx][ny] == 1
                    && (abs(arch.first - nx) + abs(arch.second - ny) <= d))
                    {// 거리가 d 이하인 적을 쐈다면
                        removed.insert({nx,ny}); // set에 적 위치 삽입
                        return; // 후 종료
                    }

                    // 쏘지 못했다면 이어서 탐색
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }

            }
        }
    }
    return;
}


int castleDefence()
{
    int score = 0; // 제거한 적의 수

    while(!gameFinished())
    {// 적이 없을때까지 반복

        // 모든 궁수가 활을 쏘고나면
        for (int i = 0; i < archer.size(); i++)
        {
            memset(visited, false, sizeof(visited));
            BFS(archer[i]);
        }
        // 제거한 적의 수만큼 답에 추가
        score += removed.size();
        // 적이 이동한다
        enemyMove();
    }
    return score;
}


void permutation(int cnt, int limit, int start)
{// 좌표계 순열 설정
    if(cnt == limit)
    {
        copyMap();
        ans = max(ans, castleDefence());
        return;
    }

    bool init = false;
    for(int j = 0; j < m; j++)
    {
        if(!init)
        {// 중복 순열 방지
            j = start;
            init = true;
        }

        if(!archerPos[n][j])
        {
            archer.push_back({n,j});
            archerPos[n][j] = true;
            permutation(cnt + 1, limit, j);
            //BackTracking
            archer.pop_back();
            archerPos[n][j] = false;
        }
    }
}

void SOLVE()
{
    permutation(0, 3, 0);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
