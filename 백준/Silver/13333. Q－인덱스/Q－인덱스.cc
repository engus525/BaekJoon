#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int paper[1001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> paper[i];
}


void solution()
{
    sort(paper, paper + n);

    for (int k = 0; k < paper[n - 1]; k++)
    {
        int idx = 0;
        int underK = 0;
        for (int i = 0; i < n; i++)
        {
            if (paper[i] <= k) underK++;
            if (paper[i] >= k)
            {
                idx = i;
                break;
            }
        }

        int overK = n - idx;
        if (k <= overK && underK >= n - k)
        {
            cout << k;
            break;
        }
    }
    if (paper[n - 1] == 0) cout << 0;
}

int main()
{
    INPUT();
    solution();
}