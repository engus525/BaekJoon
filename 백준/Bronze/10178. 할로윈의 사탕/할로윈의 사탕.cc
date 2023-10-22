#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <stack>
#include <cmath>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
int a, b;

void INPUT()
{
    IAMFAST
    cin >> t;
}


void solution()
{
    while (t--)
    {
        cin >> a >> b;
        cout << "You get " << a / b << " piece(s) and your dad gets " << a % b << " piece(s).\n";
    }
}

int main()
{
    INPUT();
    solution();
}