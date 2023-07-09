#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    int ans = 1;

    int left = 1, right = 2;
    int result = left+right;
    while (left < right && right <= n)
    {

        if (result < n) result += ++right;
        else
        {
            if(result == n) ans++;
            result -= left++;
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    solution();
}