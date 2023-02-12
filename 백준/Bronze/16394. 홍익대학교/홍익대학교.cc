#include <iostream>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;

void INPUT()
{
	IAMFAST
	cin >> n;
}

void SOLVE()
{
	cout << n-1946;
}

int main()
{
	INPUT();
	SOLVE();
}