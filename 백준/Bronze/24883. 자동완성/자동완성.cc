#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

char n;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    if (n == 'N' or n == 'n') cout << "Naver D2";
    else cout << "Naver Whale";
}

int main()
{
    INPUT();
    solution();
}