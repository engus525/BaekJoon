#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c;
int food[3];

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c;
}


void solution()
{
    cout << a * b + c;
}

int main()
{
    INPUT();
    solution();
}