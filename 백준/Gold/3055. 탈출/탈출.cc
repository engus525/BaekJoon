#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


int r, c;
char graph[51][51];
bool isWater[51][51];
int visited[51][51];
queue<pii> waterQ;
pii dir[4] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};
pii start;


void INPUT()
{
    //IAMFAST
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == '*') waterQ.emplace(i, j), isWater[i][j] = true;
            else if (graph[i][j] == 'S') start = {i, j};
        }
}

void spread_water()
{
    int qSize = int(waterQ.size());
    while (qSize--)
    {
        auto [x, y] = waterQ.front();
        waterQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || r <= nx || c <= ny) continue;
            if (graph[nx][ny] == 'X') continue;
            if (graph[nx][ny] == 'S') continue;
            if (graph[nx][ny] == 'D') continue;
            if (isWater[nx][ny]) continue;

            isWater[nx][ny] = true;
            graph[nx][ny] = '*';
            waterQ.emplace(nx, ny);
        }
    }
}

void print2d()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (visited[i][j]) cout << visited[i][j];
            else cout << graph[i][j];
        }
        cout << '\n';
    }cout << '\n';
}

string BFS()
{
    queue<pii> q;
    q.emplace(start);
    visited[start.first][start.second] = 1;

    int prev = 0;
    while (!q.empty())
    {


        auto [x, y] = q.front();
        q.pop();

        if (prev != visited[x][y]) spread_water();

        if (graph[x][y] == 'D') return to_string(visited[x][y] - 1);

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if (nx < 0 || ny < 0 || r <= nx || c <= ny) continue;
            if (graph[nx][ny] == 'X') continue;
            if (graph[nx][ny] == '*') continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = visited[x][y] + 1;
            prev = visited[x][y];
            q.emplace(nx, ny);
        }
    }
    return "KAKTUS";
}

void solution()
{
    cout << BFS();
}

int main()
{
    INPUT();
    solution();
}