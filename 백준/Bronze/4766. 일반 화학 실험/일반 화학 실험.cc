#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

double post;

void INPUT()
{
    IAMFAST
    cin >> post;
}


void solution()
{
    cout << fixed; cout.precision(2);
    double val;
    while (cin >> val)
    {
        if (val == 999) break;
        cout << val - post << '\n';
        post = val;
    }
}

int main()
{
    INPUT();
    solution();
}