#include <iostream>
#include <string>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string id;

void INPUT()
{
	IAMFAST
	cin >> id;
}

void SOLVE()
{
	cout << ":fan::fan::fan:\n";
	cout <<":fan::" << id << "::fan:\n";
	cout << ":fan::fan::fan:";

}

int main()
{
	INPUT();
	SOLVE();
}