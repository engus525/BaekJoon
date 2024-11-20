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

int n;
int psx = 0, psy = 0;
pii start = {0, 0};
vector<pii> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        v.emplace_back(x, y);
        psx += x, psy += y;
    }
}


void solution()
{
    double ans = 2e9;
    pii pos;
    for (int i = 0; i < n; i++)
    {
        double dist = sqrt(pow(abs(psx - v[i].first), 2) + pow(abs(psy - v[i].second), 2));
        ans = min(ans, dist);
    }

    cout << psx << " " << psy << '\n';
    ans = round(ans * 100) / 100;
    cout << fixed; cout.precision(2);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}