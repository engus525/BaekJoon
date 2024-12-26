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

int t;
string name;

void INPUT()
{
    IAMFAST
    cin >> t;
}

bool AZ(char c) { return 'A' <= c && c <= 'Z'; }
bool az(char c) { return 'a' <= c && c <= 'z'; }

void solution()
{
    while (t--)
    {
        cin >> name;
        if (name.length() > 10) continue;

        bool onlyNum = true;
        int azCnt = 0, AZCnt = 0;
        for (auto c : name)
        {
            if (az(c)) azCnt++, onlyNum = false;
            else if (AZ(c)) AZCnt++, onlyNum = false;
            else if (c == '-') onlyNum = false;
        }
        if (azCnt < AZCnt) continue;
        if (onlyNum) continue;
        cout << name << '\n';
        break;
    }
}

int main()
{
    INPUT();
    solution();
}