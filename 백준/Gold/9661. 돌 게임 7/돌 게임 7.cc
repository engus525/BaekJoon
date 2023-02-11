#include <iostream>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long n;

void INPUT()
{
	IAMFAST
	cin >> n;
}

void SOLVE()
{
	n %= 5;
	if(n == 0 || n == 2) cout << "CY";
	else cout << "SK";
}

int main()
{
	INPUT();
	SOLVE();
}