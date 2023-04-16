#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int ans;

void INPUT()
{
    IAMFAST
    cin >> n;
}

int recursion(string& s, int l, int r){
    ans++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string& s){
    return recursion(s, 0, s.length()-1);
}

void SOLVE()
{
    while(n--)
    {
        ans = 0;

        string str; cin >> str;
        cout << isPalindrome(str) << " " << ans << '\n';
    }

}

int main()
{
    INPUT();
    SOLVE();
}