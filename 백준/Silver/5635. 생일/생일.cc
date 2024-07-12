#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
struct INFO
{
    string name;
    int y, m, d;
};
vector<INFO> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        INFO info;
        cin >> info.name >> info.d >> info.m >> info.y;
        v.emplace_back(info);
    }
}


void solution()
{
    sort(v.begin(), v.end(), [](INFO a, INFO b)
    {
        if (a.y == b.y)
        {
            if (a.m == b.m) return a.d < b.d;
            else return a.m < b.m;
        }
        return a.y < b.y;
    });
    cout << v.back().name << "\n" << v[0].name;
}

int main()
{
    INPUT();
    solution();
}