#include <iostream>
#include <queue>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a,b,c;
bool visited[201][201][201];
set<int> ans;
struct Water
{
    int x,y,z;
};


void INPUT()
{
    IAMFAST
    cin >> a >> b >> c;
}


void BFS()
{
    queue<Water> q;
    q.push({0,0,c});

    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        if(visited[x][y][z]) continue;
        visited[x][y][z] = true;

        if(x==0) ans.insert(z);

        //a->b
        if(x+y < b) q.push({0,x+y,z});
        else q.push({x+y-b,b,z});

        //a->c
        if(x+z < c) q.push({0,y,x+z});
        else q.push({x+z-c,y,c});

        //b->a
        if(x+y < a) q.push({x+y,0,z});
        else q.push({a,x+y-a,z});

        //b->c
        if(y+z < c) q.push({x,0,y+z});
        else q.push({x,y+z-c,c});

        //c->a
        if(x+z < a) q.push({x+z,y,0});
        else q.push({a,y,x+z-a});

        //c->b
        if(y+z < b) q.push({x,y+z,0});
        else q.push({x,b,y+z-b});

    }
}

void SOLVE()
{
    BFS();
    set<int>::iterator it = ans.begin();
    for(; it != ans.end(); it++)
        cout << *it << " ";
}

int main()
{
    INPUT();
    SOLVE();
}