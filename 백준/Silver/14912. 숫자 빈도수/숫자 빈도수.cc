#include <iostream>
#include <string>
using namespace std;

int n;
char d;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> d;
}


void SOLVE()
{
    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < to_string(i).length(); j++)
        {
            if(to_string(i)[j] == d)
                ans++;
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
