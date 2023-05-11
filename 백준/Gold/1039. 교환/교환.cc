#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string n;
int k;
int ans = -1;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
}

string Swap(string str, int x, int y)
{
    char temp = str[x];
    str[x] = str[y];
    str[y] = temp;
    return str;
}

void BFS()
{
    queue<pair<string,int>> q;
    q.push({n,0});

    while(!q.empty())
    {
        unordered_set<string> visited;
        int qSize = q.size();

        for(int x = 0; x < qSize; x++)
        {
            string now = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(cnt == k+1) return;
            if(cnt == k) ans = max(ans,stoi(now));

            for(int i = 0; i < now.length()-1; i++)
                for(int j = i+1; j < now.length(); j++)
                {
                    if(i==0 && now[j]=='0') continue;

                    string next = Swap(now,i,j);
                    if(visited.find(next) != visited.end()) continue;

                    visited.insert(next);
                    q.push({next,cnt+1});

                }
        }
    }
}

void SOLVE()
{
    BFS();
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}