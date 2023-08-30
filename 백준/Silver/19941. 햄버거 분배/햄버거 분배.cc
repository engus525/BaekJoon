#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
char list[20001];

void INPUT()
{
    //IAMFAST
    cin >> n >> k;
    for(int i = 0; i < n; i++) scanf("%1s", &list[i]);
}


void solution()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if (list[i] != 'P') continue;

        for(int j = i - k; j <= i + k; j++)
        {
            if (j < 0 || j == i || j >= n) continue;
            if (list[j] == 'X' || list[j] == 'P') continue;

            ans++;
            list[j] = 'X';
            break;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}