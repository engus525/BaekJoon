#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    if (a * 7 > b * 13) cout << "Axel";
    else if (a * 7 < b * 13) cout << "Petra";
    else cout << "lika";
}

int main()
{
    INPUT();
    solution();
}