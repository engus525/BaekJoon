#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, m;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> m;
}

void solution()
{
    int num = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        int val; cin >> val;
        num += val * pow(a, i);
    }

    vector<int> v;
    while (true)
    {
        if (num / b == 0)
        {
            v.emplace_back(num);
            break;
        }
        v.emplace_back(num % b);
        num /= b;
    }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";

}

int main()
{
    INPUT();
    solution();
}