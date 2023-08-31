#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int pos[300001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num; cin >> num;
        pos[num] = i;
    }
}


void solution()
{
    int ans = 0;
    for (int i = n; i >= 2; i--)
    {
        if (pos[i] >= pos[i - 1]) continue;

        ans = i - 1;
        break;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}