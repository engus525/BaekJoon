#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int val[101];
vector<vector<int>> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i];
}


void solution()
{
    int cnt = 0;
    if (n % 2)
    {
        for (int i = 0; (n / 2) + 1 + i < n; i++)
        {
            int l = ((n / 2) - 1) - i;
            int r = ((n / 2) + 1) + i;
            if (val[l] < val[l + 1] || val[r - 1] < val[r])
            {
                int gap = max(val[l + 1] - val[l], val[r] - val[r - 1]);
                val[l] += gap;
                val[r] -= gap;
                vector<int> temp;
                for (int j = 0; j < n; j++) temp.emplace_back(val[j]);
                v.emplace_back(temp);
                cnt++;
            }
        }
    } else
    {
        for (int i = 0; i + (n / 2) < n; i++)
        {
            int l = ((n / 2) - 1) - i;
            int r = (n / 2) + i;
            if (val[l] < val[l + 1] || val[r - 1] < val[r])
            {
                int gap = max(val[l + 1] - val[l], val[r] - val[r - 1]);
                val[l] += gap;
                val[r] -= gap;
                vector<int> temp;
                for (int j = 0; j < n; j++) temp.emplace_back(val[j]);
                v.emplace_back(temp);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
    {
//        cout << i << " : ";
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}