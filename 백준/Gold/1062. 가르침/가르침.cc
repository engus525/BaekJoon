#include <iostream>
#include <string>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k;
string word[51];
bool perm[30];
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> word[i];
}

int Count()
{
    int ret = 0;
    for(int i = 0; i < n; i++)
    {
        bool canRead = true;
        for(int j = 0; j < word[i].length(); j++)
        {
            if(!perm[word[i][j]-'a'])
            {
                canRead = false;
                break;
            }
        }
        ret = (canRead) ? ret+1 : ret;
    }
    return ret;
}

void setPerm(int cnt, char start)
{
    if(cnt == k)
    {
        ans = max(ans,Count());
        return;
    }

    for(char i = start; i <= 'z'; i++)
    {
        if(i=='a' || i=='n' || i=='t' || i=='i' || i=='c') continue;

        perm[i-'a'] = true;
        setPerm(cnt+1,i+1);
        perm[i-'a'] = false;
    }
}

void SOLVE()
{
    if(k < 5) { cout << 0; return; }
    else
    {
        k -= 5;
        perm['a' - 'a'] = true;
        perm['n' - 'a'] = true;
        perm['t' - 'a'] = true;
        perm['i' - 'a'] = true;
        perm['c' - 'a'] = true;
    }

    setPerm(0,'a');
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}