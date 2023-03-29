#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
string A,B;
int ans = 2e9;

void INPUT()
{
    IAMFAST
    cin >> n >> A >> B;
}

int Greedy(bool first)
{
    int ret = 0;
    string str = A;

    if(first)
    {
        ret++;
        str[0] = (str[0] == '1') ? '0' : '1';
        str[1] = (str[1] == '1') ? '0' : '1';
    }

    for(int i = 1; i < str.length(); i++)
    {
        if(str[i-1] != B[i-1])
        {
            ret++;
            str[i - 1] = (str[i - 1] == '1') ? '0' : '1';
            str[i] = (str[i] == '1') ? '0' : '1';
            if (i + 1 < n) str[i + 1] = (str[i + 1] == '1') ? '0' : '1';
        }
    }
    if(str == B) return ret;
    else return 2e9;
}

void SOLVE()
{
    ans = min(ans,Greedy(true));
    ans = min(ans,Greedy(false));

    if(ans == 2e9) ans = -1;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}