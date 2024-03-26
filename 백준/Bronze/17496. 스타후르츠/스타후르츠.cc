#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, t, c, p;
int star[301];

void INPUT()
{
    IAMFAST
    cin >> n >> t >> c >> p;
}

void solution()
{
    int canGet = 0;
    for (int day = t + 1; day <= n; day += t) canGet++;

    cout << canGet * c * p;
}

int main()
{
    INPUT();
    solution();
}