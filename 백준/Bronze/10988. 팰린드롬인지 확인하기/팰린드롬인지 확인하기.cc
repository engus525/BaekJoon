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
    int left = 0, right = str.length()-1;

    bool ans = true;
    while(left <= right)
    {
        if(str[left] != str[right])
        {
            ans = false;
            break;
        }
        left++; right--;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}