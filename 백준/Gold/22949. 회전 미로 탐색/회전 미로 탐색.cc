#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<int,int> pii;
int k;
// [0][][] : 0도 [1][][] : 90도 [2][][] : 180도 [3][][] : 270도
char map[4][4*126][4*126];
bool visited[4][4*126][4*126];
pii dir[5] = {{0,0},{0,-1},{0,1},{-1,0},{1,0}}; // 제자리 좌 우 상 하
struct P
{
    int x;
    int y;
    int deg;
    int dist;
};
P START;


pii rotatedPos(int x,int y)
{// 회전 후 좌표를 반환한다.
    int rx = 4*((x-1)/4)+1 + (y-1)%4; // Base + Base로부터 거리
    int ry = 4*((y-1)/4)+1 + 3 - (x-1)%4; // Base + Base의 반대편 끝에서부터의 거리
    return {rx,ry};
}

void INPUT()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k;
    for(int i = 1; i <= 4*k; i++)
        for(int j = 1; j <= 4*k; j++)
        {
            scanf("%1s",&map[0][i][j]);
            if(map[0][i][j] == 'S') START = {i,j,0,0};

            int ii = i, jj = j;
            for(int deg = 1; deg <= 3; deg++)
            {// 회전된 미로를 저장해둔다.
                pii rp = rotatedPos(ii,jj);
                map[deg][rp.first][rp.second] = map[0][i][j];
                ii = rp.first; jj = rp.second;
            }
        }

}

int getArea(int x, int y)
{// 좌표가 속한 영역 번호를 반환한다.
    return (x-1)/4*4 + (y-1)/4;
}

void BFS(P start)
{
    queue<P> q;
    q.push(start);
    visited[0][start.x][start.y] = true;

    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().deg;
        int dist = q.front().dist;
        int a = getArea(x,y); // 현재 구역
        q.pop();

        for(int i = 0; i < 5; i++)
        {
            // 이동할 지점
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            
            // 이동할 영역의 번호
            int na = getArea(nx,ny);
            
            if(1 <= nx && nx <= 4*k && 1 <= ny && ny <= 4*k) // Check Range
            {
                int nd = (a == na) ? (d+1)%4 : 1; // 방문 표시할 지도의 번호(회전각도)
                pii np = rotatedPos(nx,ny); // 이동한 좌표를 회전한 후
                nx = np.first; ny = np.second;

                if(!visited[nd][nx][ny] && map[nd][nx][ny] != '#') // 회전되어 있는 지도로부터 확인
                {
                    visited[nd][nx][ny] = true;
                    q.push({nx,ny,nd,dist+1});

                    // E 도착
                    if(map[nd][nx][ny] == 'E')
                    {
                        cout << dist+1;
                        exit(0);
                    }
                }
            }// check range end
        }//for end
    }
}

void SOLVE()
{
    BFS(START);
    cout << -1;
}

int main()
{
    INPUT();
    SOLVE();
}