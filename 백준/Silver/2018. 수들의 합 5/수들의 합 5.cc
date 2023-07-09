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
    for(int i = 1; i <= n/2; i++)
    {
        int j = i+1;
        while(true)
        {
            if((i+j)*(j-i+1)/2 < n) j++;
            else if((i+j)*(j-i+1)/2 == n)
            {
                ans++;
                break;
            }
            else break;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}