#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int paint[31][3];
int gom[3];
int perm[31], moon[3];

int ans = 2e9;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> paint[i][j];
    for(int i = 0; i < 3; i++)
        cin >> gom[i];
}

void setMoon(int size)
{
    for(int i = 0; i < 3; i++)
    {
        moon[i] = 0;

        for(int j = 0; j < size; j++)
        {
            moon[i] += paint[perm[j]][i];
        }
        moon[i] /= size;
    }
}

int Gap()
{
    int gap = 0;
    for(int i = 0; i < 3; i++)
        gap += abs(gom[i] - moon[i]);
    return gap;
}

void permutation(int cnt, int limit, int start)
{
    if(cnt == limit)
    {
        setMoon(limit);
        ans = min(ans, Gap());
        return;
    }

    for(int i = start; i < n; i++)
    {
        perm[cnt] = i;
        permutation(cnt + 1, limit, i + 1);
    }
}

void SOLVE()
{
    for(int i = 2; i <= n; i++)
    {
        if(i > 7) break;
        permutation(0,i, 0);
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
