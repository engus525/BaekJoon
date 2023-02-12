#include <iostream>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int l;

void INPUT()
{
	IAMFAST
	cin >> l;
}

void SOLVE()
{
	int ans = l/5;
	if(l%5)ans++;
	cout << ans;
}

int main()
{
	INPUT();
	SOLVE();
}