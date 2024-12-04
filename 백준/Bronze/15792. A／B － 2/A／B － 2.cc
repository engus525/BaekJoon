#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    cout << a / b;
    a %= b;
    a *= 10;
    cout << ".";

    for (int i = 0; i < 1000; i++)
    {
        cout << a / b;
        a %= b;
        a *= 10;
        if (!a) break;
    }
}

int main()
{
    INPUT();
    solution();
}