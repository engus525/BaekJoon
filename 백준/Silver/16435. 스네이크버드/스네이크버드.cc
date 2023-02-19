#include <iostream>
#include <algorithm>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,l;
int L[10001];

void INPUT()
{
	IAMFAST
	cin >> n >> l;
	for(int i = 0; i < n; i++) cin >> L[i];
}


void SOLVE()
{
	sort(L,L+n);
	for(int i = 0; i < n; i++)
	{
		if(L[i] <= l) l++;
		else break;
	}
	cout << l;
}

int main()
{
	INPUT();
	SOLVE();
}