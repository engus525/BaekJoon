#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int num[4];
int total = 0;

void INPUT()
{
    IAMFAST
    for (int &i: num) cin >> i, total += i;
}

void solution()
{
    int ans = 2e9;
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 4; j++)
            ans = min(ans, abs(total - (num[i] + num[j]) - (num[i] + num[j])));
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}