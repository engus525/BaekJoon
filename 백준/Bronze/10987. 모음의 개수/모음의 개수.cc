#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str;

void INPUT()
{
    IAMFAST
    cin >> str;
}



void SOLVE()
{
    int ans = 0;
    for(auto i : str)
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
            ans++;
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}