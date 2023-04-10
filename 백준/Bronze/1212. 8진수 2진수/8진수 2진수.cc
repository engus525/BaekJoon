#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string Hex;

void INPUT()
{
    IAMFAST
    cin >> Hex;
}

string htob(int h)
{
    string ret = "";
    ret += (h/4) ? '1' : '0'; h %= 4;
    ret += (h/2) ? '1' : '0'; h %= 2;
    ret += (h/1) ? '1' : '0';
    return ret;
}

void SOLVE()
{
    string ans = "";
    for(auto i : Hex)
    {
        int num = i-'0';
        ans += htob(num);
    }

    bool flag = false;
    for(auto i : ans)
    {
        if(i == '1') flag = true;
        else if(i == '0' && !flag) continue;
        cout << i;
    }
    if(ans == "000") cout << 0;

}

int main()
{
    INPUT();
    SOLVE();
}