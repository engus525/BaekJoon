#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t;

int l,n;
vector<int> ant;

void INPUT()
{
    IAMFAST
    cin >> t;
}

/**
 * 최소 시간은 모든 개미가 양 끝 중 더 가까운 지점으로 떨어지는 시간 중 최댓값이다.
 *
 * 최대 시간은 양 끝 개미가 더 멀리 있는 끝 지점으로 떨어지는 시간 중 최댓값이다.
 * 충돌을 해도 같은 방향으로 가고있는 것과 동일하다는 것을 알 수 있기 때문이다.
 */

int findMin()
{
    int ans = 0;
    for(auto i : ant)
        ans = max(ans,min(i,l-i));
    return ans;
}

int findMax()
{
    int left = max(ant[0],l-ant[0]);
    int right = max(ant[ant.size()-1],l-ant[ant.size()-1]);
    return max(left,right);
}

void SOLVE()
{
    while(t--)
    {
        //init, input
        ant.clear();
        cin >> l >> n;
        for(int i = 0; i < n; i++)
        {
            int pos; cin >> pos;
            ant.emplace_back(pos);
        }

        sort(ant.begin(),ant.end());
        cout << findMin() << " " << findMax() << '\n';

    }
}

int main()
{
    INPUT();
    SOLVE();
}