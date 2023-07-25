#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int t;
string str;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        cin >> str;

        int total = 0;
        for (int i = 0; i < str.length(); i++)
        {
            int num = str[i] - '0';

            if (i % 2 == 1)
            {
                total += num;
                continue;
            }

            int temp = (num * 2 >= 10) ?
                    (num * 2) / 10 + (num * 2) % 10 : (num * 2);
            total += temp;
        }

        if (total % 10 == 0) cout << "T\n";
        else cout << "F\n";
    }
}

int main()
{
    INPUT();
    solution();
}