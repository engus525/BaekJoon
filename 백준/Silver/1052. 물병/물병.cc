#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, k;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
}


void solution()
{
    int ans;
    for(ans = 0; ; ans++)
    {
        int cnt = 0;
        int water = n;

        while (water)
        {
            if (water % 2) cnt++;
            water /= 2;
        }

        if (cnt <= k) break;
        else n++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}