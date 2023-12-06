#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

ll n;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    cout << n*(n-1)/2 << '\n' << 2;
}

int main()
{
    INPUT();
    solution();
}