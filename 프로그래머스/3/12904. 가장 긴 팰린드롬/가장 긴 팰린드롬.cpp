#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string str)
{
    int ans = 0;
    
    int len = str.length();
    int l = 0, r = len - 1;
    while (l < len - 1 && l <= r)
    {
        for (int i = r; i >= l; i--)
            if (str[l] == str[i])
            {
                r = i;
                break;
            }
        
        int s = l, e = r;
        // cout << l << " , " << r << " : " << str[l] << " , " << str[r] << '\n';
        bool isPalen = true;
        while (s < e)
        {
            if (str[s] != str[e])
            {
                isPalen = false;
                break;
            }
            s++, e--;
        }
        
        if (isPalen)
        {
            // cout << " ==> " << r - l + 1 << '\n';
            ans = max(ans, r - l + 1);
            l++, r = len - 1;
        }
        else r--;
    }

    return max(1, ans);
}