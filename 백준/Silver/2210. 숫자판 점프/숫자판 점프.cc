#include <iostream>
#include <string>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

char graph[5][5];
set<string> S;
pii dir[8] = {{-1, 0},
              {0,  1},
              {1,  0},
              {0,  -1}};

void INPUT()
{
    IAMFAST
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> graph[i][j];
}

void DFS(int x, int y, int cnt, string str)
{
    if (cnt == 6)
    {
        S.emplace(str);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

        str += graph[nx][ny];
        DFS(nx, ny, cnt + 1, str);
        str.pop_back();
    }
}

void solution()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            DFS(i,j,0, "");

    cout << S.size();
}

int main()
{
    INPUT();
    solution();
}