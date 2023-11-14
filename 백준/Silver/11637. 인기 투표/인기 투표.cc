#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t, n;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        cin >> n;

        int maxI = 0, maxV = 0, sum = 0;
        bool noKing = false;
        for (int i = 0; i < n; i++)
        {
            int get; cin >> get;
            sum += get;

            if (maxV == get) noKing = true;
            if (maxV < get) noKing = false, maxV = get, maxI = i + 1;
        }

        if (noKing) cout << "no winner\n";
        else if (maxV > sum / 2) cout << "majority winner " << maxI << '\n';
        else  cout << "minority winner " << maxI << '\n';
    }
}


int main()
{
    INPUT();
    solution();
}