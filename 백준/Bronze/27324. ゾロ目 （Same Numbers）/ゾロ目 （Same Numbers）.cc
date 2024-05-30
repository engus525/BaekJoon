#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    cout << ((n[0] == n[1]) ? 1 : 0);
}

int main()
{
    INPUT();
    solution();
}