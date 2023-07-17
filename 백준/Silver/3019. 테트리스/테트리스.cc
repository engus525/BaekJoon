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

int c, p;
int block[101];

void INPUT()
{
    IAMFAST
    cin >> c >> p;
    for (int i = 0; i < c; i++) cin >> block[i];
}

int f1()
{
    int ans = c;
    for (int i = 0; i <= c - 4; i++)
    {
        if (block[i] == block[i + 1] &&
            block[i + 1] == block[i + 2] &&
            block[i + 2] == block[i + 3])
            ans++;
    }
    return ans;
}

int f2()
{
    int ans = 0;
    for (int i = 0; i <= c - 2; i++)
        if (block[i] == block[i + 1]) ans++;
    return ans;
}

int f3()
{
    int ans = 0;
    for (int i = 0; i <= c - 3; i++)
        if (block[i] == block[i + 1] &&
            block[i + 1] + 1 == block[i + 2])
            ans++;
    for (int i = 0; i <= c - 2; i++)
        if (block[i] == block[i + 1] + 1) ans++;
    return ans;
}

int f4()
{
    int ans = 0;
    for (int i = 0; i <= c - 3; i++)
        if (block[i] == block[i + 1] + 1 &&
            block[i + 1] == block[i + 2])
            ans++;
    for (int i = 0; i <= c - 2; i++)
        if (block[i] + 1 == block[i + 1]) ans++;
    return ans;
}

int f5()
{
    int ans = 0;
    for (int i = 0; i <= c - 3; i++)
        if (block[i] == block[i + 1] &&
            block[i + 1] == block[i + 2])
            ans++;
    for (int i = 0; i <= c - 3; i++)
        if (block[i] == block[i + 1] + 1 &&
            block[i + 1] + 1 == block[i + 2])
            ans++;
    for (int i = 0; i <= c - 2; i++)
        if (block[i] == block[i + 1] + 1 ||
            block[i] + 1 == block[i + 1])
            ans++;
    return ans;
}

int f6()
{
    int ans = 0;
    for (int i = 0; i <= c - 2; i++)
        if (block[i] == block[i + 1] ||
            block[i] == block[i + 1] + 2)
            ans++;
    for (int i = 0; i <= c - 3; i++)
        if (block[i] == block[i + 1] &&
            block[i + 1] == block[i + 2])
            ans++;
    for (int i = 0; i <= c - 3; i++)
        if (block[i] + 1 == block[i + 1] &&
            block[i + 1] == block[i + 2])
            ans++;
    return ans;
}

int f7()
{
    int ans = 0;
    for (int i = 0; i <= c - 2; i++)
        if (block[i] == block[i + 1] ||
            block[i] + 2 == block[i + 1])
            ans++;
    for (int i = 0; i <= c - 3; i++)
        if (block[i] == block[i + 1] &&
            block[i + 1] == block[i + 2])
            ans++;
    for (int i = 0; i <= c - 3; i++)
        if (block[i] == block[i + 1] &&
            block[i + 1] == block[i + 2] + 1)
            ans++;
    return ans;
}

void solution()
{
    if (p == 1) cout << f1();
    else if (p == 2) cout << f2();
    else if (p == 3) cout << f3();
    else if (p == 4) cout << f4();
    else if (p == 5) cout << f5();
    else if (p == 6) cout << f6();
    else if (p == 7) cout << f7();
}

int main()
{
    INPUT();
    solution();
}