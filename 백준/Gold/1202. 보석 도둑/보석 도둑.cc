#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int n,k,m,v,c;
vector<int> bag;
priority_queue<pii, vector<pii>, greater<pii>> jewel;
priority_queue<int> containLimit; // Sort descending

long long ans = 0;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> m >> v;
        jewel.push({m,v});
    }
    for(int i = 0; i < k; i++)
    {
        cin >> c;
        bag.push_back(c);
    }
}


void SOLVE()
{
    // Sort bag ascending
    sort(bag.begin(), bag.end());

    int bagSize = bag.size();
    for(int i = 0; i < bagSize; i++)
    {
        // Push all jewels those bag can contain
        for(int j = 0; j < jewel.size(); j++)
        {
            if (jewel.top().first <= bag[i])
            {
                containLimit.push(jewel.top().second);
                jewel.pop();
            }
            // No more jewels to contain
            else break;
        }

        // Contain most valuable jewel
        if(!containLimit.empty())
        {
            ans += containLimit.top();
            containLimit.pop();
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
