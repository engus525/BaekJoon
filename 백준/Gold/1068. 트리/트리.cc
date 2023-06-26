#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
int root;
vector<int> graph[51];
bool visited[51];
int del;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int node; cin >> node;
        if(node == -1)
        {
            root = i;
            continue;
        }
        graph[i].emplace_back(node);
        graph[node].emplace_back(i);
    }
    cin >> del;
    visited[del] = true;
}

int DFS(int x)
{
    if(visited[x]) return 0;
    visited[x] = true;
    int ans = 0;

    bool leaf = true;
    for(int i = 0; i < graph[x].size(); i++)
    {
        int next = graph[x][i];
        if(visited[next]) continue;

        leaf = false;
        ans += DFS(next);
    }

    if(leaf) return 1;
    else return ans;
}

void SOLVE()
{
    cout << DFS(root);
}

int main()
{
    INPUT();
    SOLVE();
}