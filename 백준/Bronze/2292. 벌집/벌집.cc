#include <iostream>
using namespace std;

int n;

void INPUT()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
}


void SOLVE()
{
	int ans = 0;
	int a_n = 1;
	while (1)
	{
		if (a_n >= n)
		{
			cout << ans + 1;
			break;
		}
		a_n = a_n + 6 * (++ans);
	}
}

int main()
{
	INPUT();
	SOLVE();
}
