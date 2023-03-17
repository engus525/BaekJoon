#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

int n;
long long dp[36];

long long t(int x)
{
	if (x == 0)
		return 1;
	if (dp[x] > 0)
		return dp[x];
	else
	{
		long long value = 0;
		for (int i = 0; i < x; i++)
			value += t(i) * t(x - i - 1);

		dp[x] = value;
		return dp[x];
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;

	cout << t(n);

}
