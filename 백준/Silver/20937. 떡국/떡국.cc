#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

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
        ans = max(ans, cnt[size]);
    }
}

int main()
{
    INPUT();
    cout << ans;
}