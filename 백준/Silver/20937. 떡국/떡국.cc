#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int cnt[50001];
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int size; cin >> size;
        cnt[size]++;
        if (ans < cnt[size]) ans = cnt[size];
    }
}


void solution()
{
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}