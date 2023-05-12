#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> sensor;
vector<int> gap;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int dist; cin >> dist;
        sensor.push_back(dist);
    }
}

void SOLVE()
{
    sort(sensor.begin(), sensor.end());

    for(int i = 1; i < sensor.size(); i++)
        gap.push_back(sensor[i] - sensor[i - 1]);

    sort(gap.begin(), gap.end());

    int ans = 0;
    // gap 갯수에서 k-1개를 제거한 후 집중국 설치 : (n-1)-(k-1) = n - k
    for(int i = 0; i < n - k; i++)
        ans += gap[i];

    cout << ans;
}

int main()
{

    INPUT();
    SOLVE();
}
