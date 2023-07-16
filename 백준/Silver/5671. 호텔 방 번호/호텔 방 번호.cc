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

int n,m;

void INPUT()
{
    IAMFAST
}


void solution()
{
    while(cin >> n >> m)
    {
        int ans = 0;

        for(int room = n; room <= m; room++)
        {
            bool visited[10];
            memset(visited, false, sizeof visited);

            string str = to_string(room);
            bool canLive = true;
            for(int i = 0; i < str.length(); i++)
            {
                if (visited[str[i] - '0'])
                {
                    canLive = false;
                    break;
                }
                else visited[str[i] - '0'] = true;
            }

            if(canLive) ans++;
        }
        cout << ans << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}