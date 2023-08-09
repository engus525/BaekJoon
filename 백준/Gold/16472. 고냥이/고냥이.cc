#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int cnt[27];
string str;

void INPUT()
{
    IAMFAST
    cin >> n >> str;
}


void solution()
{
    int ans = 1;

    int left = 0, right = 0;
    cnt[str[0] - 'a']++;
    int kind = 1;

    while (right < str.length())
    {
//        cout << str[left] << " " << str[right] << " : ";
        if (kind <= n) ans = max(ans, right - left + 1);
//        cout << kind << " " << ans << '\n';

        if (kind <= n)
        {
            right++;
            if (right >= str.length()) break;
            if (cnt[str[right]  - 'a'] == 0) kind++;
            cnt[str[right] - 'a']++;
        }
        else if (kind > n)
        {
            cnt[str[left] - 'a']--;
            if (cnt[str[left] - 'a'] == 0) kind--;
            left++;
        }
        else if (left > right)
        {
            cnt[str[right] - 'a']--;
            right++;
            cnt[str[right] - 'a'] = 1;
            kind = 1;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}