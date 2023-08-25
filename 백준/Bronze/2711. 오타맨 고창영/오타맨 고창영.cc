#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}


void solution()
{
    while (t--)
    {
        int idx; cin >> idx;
        string str; cin >> str;

        for (int i = 0; i < str.length(); i++)
        {
            if (idx == i + 1) continue;
            else cout << str[i];
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}