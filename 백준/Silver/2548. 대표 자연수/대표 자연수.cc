#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<int> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int num; cin >> num;
        v.emplace_back(num);
    }
}

void solution()
{
    sort(v.begin(), v.end());
    cout << v[(n-1)/2];
}

int main()
{
    INPUT();
    solution();
}