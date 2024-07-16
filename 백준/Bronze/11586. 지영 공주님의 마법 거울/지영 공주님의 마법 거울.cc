#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
char mirror[101][101];
int d;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < str.length(); j++)
            mirror[i][j] = str[j];
    }
    cin >> d;
}

void solution()
{
    if (d == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << mirror[i][j];
            cout << '\n';
        }
    }
    else if (d == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
                cout << mirror[i][j];
            cout << '\n';
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
                cout << mirror[i][j];
            cout << '\n';
        }
    }
}

int main()
{
    INPUT();
    solution();
}