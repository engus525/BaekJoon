#include <string>
#include <vector>
#include <iostream>
typedef long long ll;

using namespace std;
vector<ll> v1, v2;
ll ans;

ll pulse(vector<ll> &v)
{
    int l = 0, r = 0;
    ll temp = v[0];
    while (l < v.size())
    {
        if (v[l] < 0)
        {
            l++, r++;
            continue;
        }
        
        temp = v[l];
        ans = max(ans, temp);
        
        while (r + 1 < v.size())
        {
            if (v[l] < 0) break;
            if (temp + v[r + 1] >= 0)
            {
                r++;
                temp += v[r];
                ans = max(ans, temp);
                if (r >= v.size()) break;
            }
            else
            {
                l = r + 2;
                r = l;
                break;
            }
        }
        
        if (r + 1 >= v.size()) break;
        
    }
    
    return ans;
}

ll solution(vector<int> v) {
    
    for (int i = 0; i < v.size(); i++)
    {
        if (!(i % 2)) v1.emplace_back(v[i]), v2.emplace_back(-v[i]);
        else v1.emplace_back(-v[i]), v2.emplace_back(v[i]);
    }
    
    
    return max(pulse(v1), pulse(v2));
}