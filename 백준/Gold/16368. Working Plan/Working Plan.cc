#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, day, w, rest;
struct INFO
{
    int workLeft;
    int canWork;
    int idx;
};

bool comp(INFO a, INFO b)
{
    if (a.workLeft == b.workLeft) return a.canWork < b.canWork;
    else return a.workLeft > b.workLeft;
}

vector<INFO> v;
int need[2001];//[i]일에 필요한 사람
int schedule[2001][2001];

void INPUT()
{
    IAMFAST
    cin >> n >> day >> w >> rest;
    for (int i = 1; i <= n; i++)
    {
        int left;
        cin >> left;
        v.push_back({left, 1, i});
    }
    for (int i = 1; i <= day; i++) cin >> need[i];
}


void solution()
{
    for (int d = 1; d <= day; d++)
    {
        sort(v.begin(), v.end(), comp);

        for (int person = 0; person < v.size(); person++)
        {
            if (need[d] <= 0) break;

            INFO now = v[person];
            if (now.canWork > d) continue;

            for (int i = d; i < d + w; i++)
            {
                //cout << now.idx << " works on " << i << '\n';
                schedule[now.idx][i] = now.idx;
                need[i]--;
            }
            now.canWork = d + w + rest;
            now.workLeft -= w;
            if (now.workLeft > 0)
            {
                v[person].workLeft = now.workLeft;
                v[person].canWork = now.canWork;
            }
            else v[person].canWork = 2e9;
        }

        if (need[d] > 0)
        {
            cout << -1;
            return;
        }

    }

    cout << 1 << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= day; j++)
        {
            //cout << schedule[i][j] << " ";
            if (schedule[i][j]) cout << j << " ", j += w;
        }
        cout << '\n';
    }


}

int main()
{
    INPUT();
    solution();
}