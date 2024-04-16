#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

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
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                for (int j = 0; j < n; j++)
                    cout << "#";
            else if (i < n - 1)
            {
                cout << "#";
                for (int j = 0; j < n - 2; j++)
                    cout << "J";
                cout << "#";
            } else
                for (int j = 0; j < n; j++)
                    cout << "#";
            cout << '\n';
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}