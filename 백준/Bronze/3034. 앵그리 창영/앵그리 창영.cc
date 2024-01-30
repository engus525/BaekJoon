#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
double w, h;
double len;

void INPUT()
{
    IAMFAST
    cin >> n >> w >> h;
}

void solution()
{
    double limit = sqrt(w*w + h*h);

    while (n--)
    {
        cin >> len;
        if (len <= limit) cout << "DA\n";
        else cout << "NE\n";
    }
}

int main()
{
    INPUT();
    solution();
}