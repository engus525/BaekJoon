#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int sum = 0;

void INPUT()
{
    IAMFAST
}


void solution()
{
    int n;
    while (cin >> n)
    {
        if (n == -1) break;
        sum += n;
    }
    cout << sum;
}

int main()
{
    INPUT();
    solution();
}