#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,a,b,c;
int li[3];
struct Mutal
{
    int a,b,c;
};
bool visited[61][61][61];

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> li[i];
    a = li[0]; b = li[1]; c = li[2];
}

int BFS()
{
    queue<Mutal> q;
    q.push({a,b,c});

    int ans = 0;
    while(!q.empty())
    {
        int qSize = q.size();

        for(int i = 0; i < qSize; i++)
        {
            auto [x, y, z] = q.front();
            q.pop();

            if (x == 0 && y == 0 && z == 0) return ans;

            if (visited[x][y][z]) continue;
            visited[x][y][z] = true;

            q.push({max(0,x-9),max(0,y-3),max(0,z-1)});
            q.push({max(0,x-9),max(0,y-1),max(0,z-3)});
            q.push({max(0,x-3),max(0,y-9),max(0,z-1)});
            q.push({max(0,x-1),max(0,y-9),max(0,z-3)});
            q.push({max(0,x-3),max(0,y-1),max(0,z-9)});
            q.push({max(0,x-1),max(0,y-3),max(0,z-9)});
        }
        ans++;
    }
}

void SOLVE()
{
    cout << BFS();
}

int main()
{
    INPUT();
    SOLVE();
}