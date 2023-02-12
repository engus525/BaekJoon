#include <iostream>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
int a[101][101];

void INPUT()
{
	IAMFAST
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			a[i][j] += num;
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}

void SOLVE()
{
}

int main()
{
	INPUT();
	SOLVE();
}