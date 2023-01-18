#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,s;
vector<int> v;

int ans = 0;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        v.push_back(num);
    }
}

void permutation(int cnt)
{
    vector<int> visit;
    for(int i = 0; i < n - cnt; i++) visit.push_back(0);
    for(int i = 0; i < cnt; i++) visit.push_back(1);

    do
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
            if(visit[i] == 1)
                sum += v[i];

        if(sum == s) ans++;
    }
    while(next_permutation(visit.begin(), visit.end()));
    
}

void SOLVE()
{
    sort(v.begin(),v.end());
    for(int i = 1; i <= n; i++)
        permutation(i);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
