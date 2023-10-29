#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void solution()
{
    cin.ignore();
    while (n--)
    {
        string str;
        getline(cin, str);

        int tempDepth = 0, depth = 0;
        for (auto &s : str)
        {
            if (s == '[') tempDepth++;
            else tempDepth--;

            depth = max(depth, tempDepth);
        }

        cout << int(pow(2,depth)) << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}