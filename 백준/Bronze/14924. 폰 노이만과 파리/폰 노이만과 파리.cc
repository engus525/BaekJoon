#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int s,t,d;

void INPUT()
{
    IAMFAST
    cin >> s >> t >> d;
}

void solution()
{
    cout << t * d / (2 * s);
}

int main()
{
    INPUT();
    solution();
}