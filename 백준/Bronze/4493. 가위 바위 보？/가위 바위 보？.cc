#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

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
        int n; cin >> n;
        int one = 0;
        while (n--)
        {
            char a, b;
            cin >> a >> b;
            if (a == b) continue;
            else if (a == 'P' && b == 'R') one++;
            else if (a == 'R' && b == 'S') one++;
            else if (a == 'S' && b == 'P') one++;
            else one--;
        }
        if (one > 0) cout << "Player 1\n";
        else if (one == 0) cout << "TIE\n";
        else if (one < 0) cout << "Player 2\n";
    }
}

int main()
{
    INPUT();
    solution();
}