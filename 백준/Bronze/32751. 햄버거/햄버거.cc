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

int cnt[4];
int n;
string str;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < 4; i++) cin >> cnt[i];
    cin >> str;
}

void solution()
{
    bool good = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[0] != 'a' || str.back() != 'a') good = false;
        if (i && str[i] == str[i - 1]) good = false;
        if (cnt[str[i] - 'a'] == 0) good = false;
        if (!good) break;

        cnt[str[i] - 'a']--;
    }

    cout << (good ? "Yes" : "No");
}

int main()
{
    INPUT();
    solution();
}