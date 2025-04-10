#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

vector<pii> v;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    for (auto station : stations)
        v.emplace_back(station - w, station + w);
    
    int l = 1, r = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (l > n) break;
        // cout << l << " ~ " << r << '\n';
        
        if (v[i].first <= l && l <= v[i].second)
        {
            l = r = v[i].second + 1;
            continue;
        }
        else
        {
            r = v[i].first - 1;
            // cout << l << "부터 " << r << "까지 채워야함\n";
            answer += (r - l + 1) / (2 * w + 1);
            if ((r - l + 1) % (2 * w + 1)) answer++;
            l = r = v[i].second + 1;
        }
    }
    
    if (l <= n) 
    {
        // cout << l << "부터 " << n << "까지 채워야함\n";
        answer += (n - l + 1) / (2 * w + 1);
        if ((n - l + 1) % (2 * w + 1)) answer++;
    }

    return answer;
}