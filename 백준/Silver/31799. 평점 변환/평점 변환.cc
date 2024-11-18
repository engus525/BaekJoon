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
string str;

map<string, int> M;

void INPUT()
{
    IAMFAST
    cin >> n >> str;
}

bool isABC(char c)
{
    return (c == 'A' || c == 'B' || c == 'C');
}

void solution()
{
    M.emplace("A+", 9);
    M.emplace("A0", 8);
    M.emplace("A-", 7);
    M.emplace("B+", 6);
    M.emplace("B0", 5);
    M.emplace("B-", 4);
    M.emplace("C+", 3);
    M.emplace("C0", 2);
    M.emplace("C-", 1);
    string ans;

    int before = 0;
    for (int i = 0; i < str.length(); i++)
    {
        string grade;
        grade += str[i];
        if (i + 1 < str.length() && !isABC(str[i + 1])) grade += str[i + 1], i++;
        else grade += "0";
        int now = M[grade];

        if (now <= 3) ans += "B";
        else if (now <= 5)
        {
            if (!i || before <= 3) ans += "D";
            else ans += "B";
        }
        else if (now <= 7)
        {
            if (!i || before <= 5) ans += "P";
            else ans += "D";
        }
        else if (now == 8)
        {
            if (!i || before <= 7) ans += "E";
            else ans += "P";
        }
        else ans += "E";

        before = now;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}