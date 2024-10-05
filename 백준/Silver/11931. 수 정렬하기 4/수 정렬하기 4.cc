#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        v.emplace_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << '\n';
}

int main()
{
    INPUT();
    solution();
}