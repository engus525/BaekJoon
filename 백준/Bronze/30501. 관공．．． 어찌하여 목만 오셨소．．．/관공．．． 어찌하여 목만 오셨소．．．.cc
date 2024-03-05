#include <bits/stdc++.h>

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
    while (n--)
    {
        string str;
        cin >> str;

        for (auto s : str)
        {
            if (s == 'S')
            {
                cout << str;
                return;
            }
        }
    }
}

int main()
{
    INPUT();
    solution();
}