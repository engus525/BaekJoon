#include <iostream>
#include <string>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k;

void INPUT()
{
	IAMFAST
	cin >> n >> k;
}

bool In(int num)
{
	string str = to_string(num);
	if(str.length() == 1) str = "0" + str;
	return str[0]-'0' == k || str[1]-'0' == k;
}

void SOLVE()
{
	int ans = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 60; j++)
			for(int t = 0; t < 60; t++)
				if(In(i) || In(j) || In(t)) ans++;
	cout << ans;
}

int main()
{
	INPUT();
	SOLVE();
}