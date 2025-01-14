#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string str[51];
bool isUnique[51];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str[i];
}

void solution()
{
    memset(isUnique, true, sizeof isUnique);

    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (!isUnique[i]) continue;

        for (int j = i + 1; j < n; j++)
        {
            if (str[i].length() != str[j].length()) continue;

            int len = str[i].length();
            bool isSameStr = false;
            for (int idx = 0; idx < len; idx++)
            {
                bool allSame = true;
                for (int mov = 0; mov < len; mov++)
                {
                    if (str[i][mov] != str[j][(idx + mov) % len])
                    {
                        allSame = false;
                        break;
                    }
                }
                if (allSame)
                {
                    isSameStr = true;
                    break;
                }
            }
            if (isSameStr)
            {
                isUnique[j] = false;
                ans--;
            }
        }
    }

    cout << ans;
}


int main()
{
    INPUT();
    solution();
}