#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a,b,c;
bool visited[1501][1501];
struct Rock
{
    int a,b,c;
};

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c;
}

bool BFS()
{
    queue<Rock> q;
    q.push({a,b,c});

    while(!q.empty())
    {
        auto [x,y,z] = q.front();
        q.pop();

        if(x==y && y==z) return true;

        if(visited[x][y]) continue;
        visited[x][y] = true;

        if((x != 2*y) && (x > y)) q.push({x-y,y+y,z});
        if((y != 2*x) && (x < y)) q.push({x+x,y-x,z});
        if((y != 2*z) && (y > z)) q.push({x,y-z,z+z});
        if((z != 2*y) && (y < z)) q.push({x,y+y,z-y});
        if((z != 2*x) && (z > x)) q.push({x+x,y,z-x});
        if((x != 2*z) && (z < x)) q.push({x-z,y,z+z});
    }
    return false;
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