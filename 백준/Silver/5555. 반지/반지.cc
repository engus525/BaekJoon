#include <iostream>
#include <string>
using namespace std;

string target;
int n;
string ring[101];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> target >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> ring[i];
        ring[i] += ring[i];
    }
}


void SOLVE()
{
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(ring[i].substr(j,target.length())
            == target)
            {
                ans++;
                break;
            }
            else continue;
        }
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
