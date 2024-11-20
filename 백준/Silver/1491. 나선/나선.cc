#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <thread>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
int cnt = 0;
int x = -1, y = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
}

void Print()
{
    cout << x << " " << y << '\n';
}

void end()
{
    if (cnt == n * m)
    {
        Print();
        exit(0);
    }
}

void solution()
{
    int rotateCnt = 0;
    while (true)
    {
        while (x < n - 1 - rotateCnt) x++, cnt++;
        end();
        while (y < m - 1 - rotateCnt) y++, cnt++;
        end();
        while (x > rotateCnt) x--, cnt++;
        end();
        while (y > rotateCnt + 1) y--, cnt++;
        end();

        rotateCnt++;
    }
}

int main()
{
    INPUT();
    solution();
}