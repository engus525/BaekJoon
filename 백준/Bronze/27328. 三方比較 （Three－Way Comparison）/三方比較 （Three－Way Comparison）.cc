#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a,b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;

}



void solution()
{
    (a < b) ? (cout << -1) : ((a == b) ? (cout << 0) : (cout << 1));
}

int main()
{
    INPUT();
    solution();
}