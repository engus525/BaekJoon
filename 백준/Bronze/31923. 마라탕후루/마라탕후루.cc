#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c;
int x[101], y[101];
int ans[101];

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c;
    for (int i = 0; i < a; i++) cin >> x[i];
    for (int i = 0; i < a; i++) cin >> y[i];
}


void solution()
{
    bool successYN = true;
    for (int i = 0; i < a; i++)
    {
        int cnt = (b == c) ?
                  ((y[i] == x[i]) ? 0 : -1) :
                  ((y[i] - x[i]) % (b - c) ? -1 : (y[i] - x[i]) / (b - c));
        if (cnt > 10000 || cnt < 0)
        {
            successYN = false;
            break;
        }
        ans[i] = cnt;
    }

    if (!successYN) cout << "NO";
    else
    {
        cout << "YES\n";
        for (int i = 0; i < a; i++) cout << ans[i] << " ";
    }
}

int main()
{
    INPUT();
    solution();
}