#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a, b, c, d, e, f;

void INPUT()
{
    IAMFAST
}

void solution()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b >> c >> d >> e >> f;

        int h = d - a;

        int m = e - b;
        if (m < 0) m += 60, h--;

        int s = f - c;
        if (s < 0) s += 60, m--;
        if (m < 0) m += 60, h--;

        cout << h << " " << m << " " << s << '\n';
    }
}


int main()
{
    INPUT();
    solution();
}