#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;
int ps[1001];

void INPUT()
{
    IAMFAST
    cin >> str;
}

void solution()
{
    ps[0] = str[0] - '0';
    for (int i = 1; i < str.length(); i++)
        ps[i] = ps[i - 1] + (str[i] - '0');

    int ans = 0;
    for (int i = 0; i < str.length() - 1; i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if ((j - i) % 2 == 0) continue;

            int ll = i, lr = i + (j - i) / 2;
            int rl = lr + 1, rr = j;

            int lSum = ps[lr] - ((ll - 1) < 0 ? 0 : ps[ll - 1]);
            int rSum = ps[rr] - ps[rl - 1];
            if (lSum != rSum) continue;
            ans = max(ans, rr - ll + 1);
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}