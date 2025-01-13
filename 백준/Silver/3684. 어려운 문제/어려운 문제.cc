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

int t;
ll list[201];

void INPUT()
{
    IAMFAST
    cin >> t;
    for (int i = 0; i < t; i++) cin >> list[i];
}

void solution()
{
    ll ansA = -1, ansB = -1;
    for (ll a = 0; a <= 10000; a++)
    {
        for (ll b = 0; b <= 10000; b++)
        {
            bool foundAB = true;
            for (int i = 0; i < t - 1; i++)
            {
                ll output = (a * list[i] + b) % 10001;
                if ((a *output + b) % 10001 != list[i + 1])
                {
                    foundAB = false;
                    break;
                }
            }

            if (foundAB)
            {
                ansA = a, ansB = b;
                break;
            }
        }
        if (ansA != -1) break;
    }

    for (int i = 0; i < t; i++)
        cout << (ansA * list[i] + ansB) % 10001 << '\n';
}


int main()
{
    INPUT();
    solution();
}