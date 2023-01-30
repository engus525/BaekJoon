#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n, m;
long long tree[1'000'001];
long long ans = 0;

void INPUT()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
}


void SOLVE()
{
	for (int i = 0; i < n; i++)
		cin >> tree[i];

	
	long long low = 0, high = *max_element(tree, tree + n);
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long result = 0;
		for (int i = 0; i < n; i++)
		{
			if (tree[i] > mid)
				result += tree[i] - mid;
		}

		if (result >= m)
		{
			ans = mid;
			low = mid + 1;
		}
		else if (result < m)
		{
			high = mid - 1;
		}

	}
	cout << ans;

}

int main()
{
	INPUT();
	SOLVE();
}
