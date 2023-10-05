#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, money, cnt;
vector<int> v;
bool visited[100001];

void INPUT()
{
    IAMFAST
    cin >> n >> money >> cnt;
    for (int i = 0; i < n; i++)
    {
        int price; cin >> price;
        v.emplace_back(price);
    }
}

void solution()
{
    sort(v.begin(), v.end());

    int ans = 0;

    int spend = 0;
    for (int i = 0; i < n; i++)
    {
        if (spend + v[i] <= money) ans++, spend += v[i];
        else
        {
            bool bought = false;
            for (int rev = i; rev >= 0; rev--)
            {
                if (cnt == 0) break;
                if (visited[rev]) continue;

                visited[rev] = true;
                cnt--;
                spend -= v[rev] / 2;
                if (spend + v[i] <= money)
                {
                    bought = true, spend += v[i], ans++;
                    break;
                }
            }
            if (!bought) break;
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    solution();
}