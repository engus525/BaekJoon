#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int s, k, h;

void INPUT()
{
    IAMFAST
    cin >> s >> k >> h;
}

void solution()
{
    if (s + k + h < 100)
    {
        if (s < k && s < h) cout << "Soongsil";
        else if (k < s && k < h) cout << "Korea";
        if (h < s && h < k) cout << "Hanyang";
    }
    else cout << "OK";
}

int main()
{
    INPUT();
    solution();
}