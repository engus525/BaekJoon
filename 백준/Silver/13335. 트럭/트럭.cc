#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, w, l;
int truck[1001];
queue<int> bridge;

void INPUT()
{
    IAMFAST
    cin >> n >> w >> l;
    for (int i = 0; i < n; ++i) cin >> truck[i];
}

void solution()
{
    int ans = 0;
    int l_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        while (true)
        {
            if (bridge.size() == w)
            {
                l_sum -= bridge.front();
                bridge.pop();
            }

            if (l_sum + truck[i] <= l) break;
            bridge.emplace(0);
            ans++;
        }

        bridge.emplace(truck[i]);
        l_sum += truck[i];
        ans++;
    }
    cout << ans + w;
}

int main()
{
    INPUT();
    solution();
}