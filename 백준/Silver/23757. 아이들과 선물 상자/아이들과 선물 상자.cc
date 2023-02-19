#include <iostream>
#include <queue>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
priority_queue<int> c;
int w[100001];

bool ans = true;

void INPUT()
{
	IAMFAST
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int gift; cin >> gift;
		c.push(gift);
	}
	for(int i = 0; i < m; i++) cin >> w[i];
}


void SOLVE()
{
	for(int i = 0; i < m; i++)
	{
		int top = c.top();

		if(top >= w[i]) c.pop() , c.push(top-w[i]);
		else
		{
			ans = false;
			break;
		}
	}
	cout << ans;
}

int main()
{
	INPUT();
	SOLVE();
}