#include <iostream>
#include <map>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    cout << (n*(n+1)/2) << '\n';
    cout << (n*(n+1)/2)*(n*(n+1)/2) << '\n';
    cout << (n*(n+1)/2)*(n*(n+1)/2);
}

int main()
{
    INPUT();
    solution();
}