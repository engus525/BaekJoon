#include <iostream>
#include <stack>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int B;

void INPUT()
{
    IAMFAST
    cin >> n >> B;
}

void SOLVE()
{
    stack<char> ans;
    while(n)
    {
        if(n%B < 10) ans.push(char(n%B)+'0');
        else ans.push(char(n%B)+'A'-10);
        n /= B;
    }
    while(!ans.empty()) cout<<ans.top(),ans.pop();
}

int main()
{
    INPUT();
    SOLVE();
}