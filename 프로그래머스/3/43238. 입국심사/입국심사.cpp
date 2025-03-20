#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solution(int n, vector<int> times) {
    ll answer = 2e18;
    
    ll l = 0, r = n * ll(*max_element(times.begin(), times.end()));
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        
        ll pass = 0;
        for (auto time : times) pass += mid / ll(time);
        
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