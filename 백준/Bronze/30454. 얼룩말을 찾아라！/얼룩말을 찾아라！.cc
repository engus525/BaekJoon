#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void solution()
{
    int maxCnt = 0, ansCnt = 0;
    for (int i = 0; i < a; i++)
    {
        string str; cin >> str;
        int cnt = 0;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '1')
            {
                cnt++;
                while (j <= str.length() - 1 && str[j] == '1') j++;
            }
        }

        if (maxCnt == cnt) ansCnt++;
        else if (maxCnt < cnt) maxCnt = cnt, ansCnt = 1;
    }

    cout << maxCnt << " " << ansCnt << '\n';
}

int main()
{
    INPUT();
    solution();
}