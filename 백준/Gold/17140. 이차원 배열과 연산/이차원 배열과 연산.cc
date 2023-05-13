#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int r, c, k;
int rowNum = 3, colNum = 3;
int A[101][101];
typedef pair<int, int> pii;

bool comp(pii &a, pii &b)
{
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void INPUT()
{
    IAMFAST
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> A[i][j];
}

vector<pii> sortMap(map<int, int> &M)
{
    vector<pii> v(M.begin(), M.end());
    sort(v.begin(), v.end(), comp);
    return v;
}


void RC(bool isRow)
{
    priority_queue<int> pq;
    int maxSize = 0;
    for (int i = 1; i <= (isRow ? rowNum : colNum); i++)
    {
        map<int, int> M;
        for (int j = 1; j <= (isRow ? colNum : rowNum); j++)
        {
            int value = isRow ? A[i][j] : A[j][i];
            if (value == 0) continue;
            if (M.find(value) == M.end()) M.insert({value, 1});
            else M[value]++;
        }

        vector<pii> v = sortMap(M);

        pq.push(2 * v.size());

        maxSize = max(maxSize, (int) v.size() * 2);

        for (int j = 1; j <= 100; j++)
        {
            if (isRow) A[i][j] = 0;
            else A[j][i] = 0;
        }

        int idx = 1;
        for (auto j: v)
        {
            if (idx > 100) break;
            if (isRow)
            {
                A[i][idx] = j.first;
                A[i][idx + 1] = j.second;
            } else
            {
                A[idx][i] = j.first;
                A[idx + 1][i] = j.second;
            }
            idx += 2;
        }
    }

    if (isRow)
    {
        colNum = min(100, maxSize);
    } else
    {
        rowNum = min(100, maxSize);
    }
}

void SOLVE()
{
    int ans = 0;
    while (A[r][c] != k)
    {
        if (ans == 101) break;
        ans++;

        if (rowNum >= colNum) RC(true);
        else RC(false);

    }
    if (ans == 101) cout << -1;
    else cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}