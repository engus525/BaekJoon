#include <iostream>

using namespace std;

int k;
int lotto[13];
int ans[6];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

}

void permutation(int cnt, int start)
{
    if(cnt == 6)
    {
        for(int i = 0; i < 6; i++) cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = start; i < k; i++)
    {
        ans[cnt] = lotto[i];
        permutation(cnt + 1, i + 1);
    }
}

void SOLVE()
{
    while(cin >> k)
    {
        if(!k) break;

        // Input
        for(int i = 0; i < k; i++) cin >> lotto[i];

        permutation(0, 0);
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}
