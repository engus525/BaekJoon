#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solution(int n, vector<int> times) {
    ll answer = 2e18;
    
    ll l = 0, r = 1e18;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        
        ll pass = 0;
        for (auto time : times) pass += mid / time;
        
        if (pass >= n)
        {
            answer = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    
    
    return answer;
}