#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

double d, h, w;

void INPUT()
{
    IAMFAST
    cin >> d >> h >> w;
}


void solution()
{
    double value = sqrt(d * d * h * h / (w * w + h * h));
    cout << int(value) << " " << int(value * w / h);
}

int main()
{
    INPUT();
    solution();
}