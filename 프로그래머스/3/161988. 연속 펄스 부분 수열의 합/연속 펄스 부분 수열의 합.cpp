#include <string>
#include <vector>
#include <iostream>
typedef long long ll;

using namespace std;
vector<ll> v1, v2;
ll ans;

ll solution(vector<int> v) {
    
    for (int i = 0; i < v.size(); i++)
    {
        if (!(i % 2)) v1.emplace_back(v[i]), v2.emplace_back(-v[i]);
        else v1.emplace_back(-v[i]), v2.emplace_back(v[i]);
    }
    
    int l = 0, r = 0;
    ll temp = v1[0];
    while (l < v.size())
    {
        if (v1[l] < 0)
        {
            l++, r++;
            continue;
        }
        // cout << l << " , " << r << '\n';
        
        temp = v1[l];
        ans = max(ans, temp);
        
        while (r + 1 < v.size())
        {
            if (v1[l] < 0) break;
            // cout << "idx : " << l << " , " << r << '\n';
            // cout << "val : " << v1[l] << " , " << v1[r] << '\n';
            if (temp + v1[r + 1] >= 0)
            {
                // cout << "Move R\n";
                r++;
                temp += v1[r];
                ans = max(ans, temp);
                if (r >= v.size()) break;
            }
            else
            {
                // cout << "BREAK\n";
                l = r + 2;
                r = l;
                break;
            }
        }
        
        if (r + 1 >= v.size()) break;
        
    }
    
    l = 0, r = 0;
    ll temp2 = v2[0];
    while (l < v.size())
    {
        if (v2[l] < 0)
        {
            l++, r++;
            continue;
        }
        // cout << l << " , " << r << '\n';
        
        temp2 = v2[l];
        ans = max(ans, temp2);
        
        while (r + 1 < v.size())
        {
            if (v2[l] < 0) break;
            // cout << "idx : " << l << " , " << r << '\n';
            // cout << "val : " << v2[l] << " , " << v2[r] << '\n';
            if (temp2 + v2[r + 1] >= 0)
            {
                // cout << "Move R\n";
                r++;
                temp2 += v2[r];
                ans = max(ans, temp2);
                if (r >= v.size()) break;
            }
            else
            {
                // cout << "BREAK\n";
                l = r + 2;
                r = l;
                break;
            }
        }
        
        if (r + 1 >= v.size()) break;
        
    }
    
    
    return ans;
}