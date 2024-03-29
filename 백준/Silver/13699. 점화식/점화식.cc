#include <iostream>
using namespace std;

int n;
long long dp[36];

long long t(int x)
{
	if (x == 0) return 1;
	if (dp[x]) return dp[x];
    
    for (int i = 0; i < x; i++)
        dp[x] += t(i) * t(x - i - 1);

    return dp[x];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	cout << t(n);
}
