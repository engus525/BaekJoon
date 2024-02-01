#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string a;

void INPUT()
{
    IAMFAST
    cin >> n >> a;
}

void solution()
{
    for (int i = a.length() - 5; i < a.length(); i++) cout << a[i];
}

int main()
{
    INPUT();
    solution();
}