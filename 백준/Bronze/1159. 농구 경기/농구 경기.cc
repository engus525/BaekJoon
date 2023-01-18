#include <iostream>
#include <string>
using namespace std;

int n;
int cnt[27];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        cnt[name[0] - 'a']++;
    }
}


void SOLVE()
{
    bool surrender = true;
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] >= 5)
        {
            surrender = false;
            cout << char(i + 'a');
        }
    }
    if(surrender) cout << "PREDAJA";
}

int main()
{
    INPUT();
    SOLVE();
}