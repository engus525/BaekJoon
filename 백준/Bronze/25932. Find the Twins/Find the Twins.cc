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
        vector<int> v;
        bool zack = false, mack = false;
        for (int i = 0; i < 10; i++)
        {
            int num; cin >> num;
            if (num == 17) zack = true;
            if (num == 18) mack = true;

            v.emplace_back(num);
        }

        for (auto val : v) cout << val << " ";
        cout << '\n';
        if (zack && mack) cout << "both\n";
        else if (zack) cout << "zack\n";
        else if (mack) cout << "mack\n";
        else cout << "none\n";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}