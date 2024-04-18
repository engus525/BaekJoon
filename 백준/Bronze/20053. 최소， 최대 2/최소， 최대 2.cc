#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        int n; cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int num; cin >> num;
            v.emplace_back(num);
        }
        sort(v.begin(), v.end());

        cout << v[0] << " " << v[n - 1] <<  '\n';
    }
}

int main()
{
    INPUT();
    solution();
}