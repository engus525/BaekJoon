#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t,a,b;
vector<int> A,B;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}


void SOLVE()
{
    while(t--)
    {
        //Input
        cin >> a >> b;
        for(int i = 0; i < a; i++)
        {
            int ai; cin >> ai;
            A.push_back(ai);
        }
        for(int i = 0; i < b; i++)
        {
            int bi; cin >> bi;
            B.push_back(bi);
        }

        //이분탐색 위해 정렬
        sort(A.begin(),A.end());

        int ans = 0;
        for(int i = 0; i < b; i++)
        {//B의 각 원소에 대해

            int left = 0 , right = a-1;

            //이분탐색 진행
            int idx = -1;
            while(left <= right)
            {
                int mid = (left + right) / 2;

                if(A[mid] <= B[i]) idx = mid , left = mid + 1;
                else right = mid - 1;
            }

            ans += (a-1) - idx;
        }

        cout << ans << '\n';
        A.clear(); B.clear();
    }
}

int main()
{
    INPUT();
    SOLVE();
}