#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
int n,m;
char map[101][101];
int area[101][101];
bool visited[101][101];
// 오른쪽 시작으로 시계방향 : 우 하 좌 상
pii dirDP[4] = {{0,1},{1,0},{0,-1},{-1,0}};
int dp = 0, cc = 0;
int nowX = 0,nowY = 0;


void INPUT()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%1s", &map[i][j]);
}

bool Move(int x,int y)
{
    int nx = x + dirDP[dp].first;
    int ny = y + dirDP[dp].second;
    if((0 <= nx && nx < n && 0 <= ny && ny < m) &&
       map[nx][ny] != 'X')
    {
        nowX = nx;
        nowY = ny;

        cout << map[nowX][nowY];
        return true;
    }
    return false;
}

void Find()
{
    /*총 8가지의 경우를 모두 시도했는데도 이동할 수 있는 블록을 찾지 못한 경우,
        프로그램이 종료된다.*/
    for(int cnt = 0; cnt < 8; cnt++)
    {
        // cc값 전환 후 이동 시도
        if(cnt % 2 == 1) cc = 1 - cc;
        // dp 방향 회전 후 이동 시도
        else if(cnt % 2 == 0 && cnt > 0) dp = (dp+1)%4;

        bool breaked = false;
        if(dp == 0)
        {
            for(int i = m-1; i >= 0; i--)
            {
                if(cc == 0)
                {
                    for (int j = 0; j < n; j++)
                        if (map[j][i] == map[nowX][nowY]
                        && area[j][i] == area[nowX][nowY])
                        {
                            if(Move(j,i)) return;
                            else
                            {
                                breaked = true;
                                break;
                            }
                        }
                    if(breaked) break;
                }
                else
                {
                    for(int j = n-1; j >= 0; j--)
                        if(map[j][i] == map[nowX][nowY]
                           && area[j][i] == area[nowX][nowY])
                        {
                            if(Move(j,i)) return;
                            else
                            {
                                breaked = true;
                                break;
                            }
                        }
                    if(breaked) break;
                }
            }
        }//dp 0 end


        else if(dp == 1)
        {
            for(int i = n-1; i >= 0; i--)
            {
                if(cc == 0)
                {
                    for (int j = m-1; j >= 0; j--)
                        if (map[i][j] == map[nowX][nowY]
                            && area[i][j] == area[nowX][nowY])
                        {
                            if(Move(i, j)) return;
                            else
                            {
                                breaked = true;
                                break;
                            }
                        }
                    if(breaked) break;
                }
                else
                {
                    for(int j = 0; j < m; j++)
                        if(map[i][j] == map[nowX][nowY]
                           && area[i][j] == area[nowX][nowY])
                        {
                            if(Move(i,j)) return;
                            else
                            {
                                breaked = true;
                                break;
                            }
                        }
                    if(breaked) break;
                }
            }
        }//dp 1 end


        else if(dp == 2)
        {
            for(int i = 0; i < m; i++)
            {
                if(cc == 0)
                {
                    for (int j = n-1; j >= 0; j--)
                        if (map[j][i] == map[nowX][nowY]
                            && area[j][i] == area[nowX][nowY])
                        {
                            if(Move(j,i)) return;
                            else
                            {
                                breaked = true;
                                break;
                            }
                        }
                    if(breaked) break;
                }

                else
                {
                    for(int j = 0; j < n; j++)
                        if(map[j][i] == map[nowX][nowY]
                           && area[j][i] == area[nowX][nowY])
                        {
                            if(Move(j,i)) return;
                            else
                            {
                                breaked = true;
                                break;
                            }
                        }
                    if(breaked) break;
                }
            }
        }//dp 2 end

        else
        {
            for(int i = 0; i < n; i++)
            {
                if(cc == 0)
                {
                    for (int j = 0; j < m; j++)
                        if (map[i][j] == map[nowX][nowY]
                            && area[i][j] == area[nowX][nowY])
                        {
                            if(Move(i, j)) return;
                            else
                            {
                                breaked = true;
                                break;
                            }
                        }
                    if(breaked) break;
                }
                else
                {
                    for(int j = m-1; j >= 0; j--)
                        if(map[i][j] == map[nowX][nowY]
                           && area[i][j] == area[nowX][nowY])
                        {
                            if(Move(i,j)) return;
                            else
                            {
                                breaked = true;
                                break;
                            }
                        }
                    if(breaked) break;
                }
            }
        }//dp 3 end

    }

    // 이동 불가능
    exit(0);
}

void BFS(int x,int y,int mk)
{
    queue<pii> q;
    q.push({x,y});
    visited[x][y] = true;
    area[x][y] = mk;

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dirDP[i].first;
            int ny = y + dirDP[i].second;

            if(!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
            if(visited[nx][ny]) continue;

            if(map[x][y] == map[nx][ny])
            {
                visited[nx][ny] = true;
                area[nx][ny] = mk;
                q.push({nx,ny});
            }
        }
    }
}

void SOLVE()
{
    cout << map[nowX][nowY];

    //영역 표시
    int mark = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!visited[i][j] && map[i][j] != 'X')
            {
                BFS(i,j,mark);
                mark++;
            }

    while(true) Find();
}

int main()
{
    INPUT();
    SOLVE();
}