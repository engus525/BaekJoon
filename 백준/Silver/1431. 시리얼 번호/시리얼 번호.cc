#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<string> v;

bool isNum(char c)
{
    return ('0' <= c && c <= '9');
}

bool comp(string a, string b)
{
    if (a.length() == b.length())
    {
        int aSum = 0, bSum = 0;
        for (char i: a)
            if (isNum(i))
                aSum += i - '0';
        for (char i: b)
            if (isNum(i))
                bSum += i - '0';

        if (aSum == bSum)
        {
            for (int i = 0; i < a.length(); i++)
            {
                if (a[i] == b[i]) continue;
                else if (isNum(a[i]) && !isNum(b[i])) return true;
                else if (!isNum(a[i]) && isNum(b[i])) return false;
                else return a < b;
            }
        }
        return aSum < bSum;
    } else return a.length() < b.length();
}

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.emplace_back(str);
    }
}

void solution()
{
    sort(v.begin(), v.end(), comp);
    for (auto str: v) cout << str << '\n';
}

int main()
{
    INPUT();
    solution();
}