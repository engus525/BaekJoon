#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int A[28];
deque<int> ans,L,R;


void INPUT()
{
    IAMFAST
    cin >> n;
}




void SOLVE()
{
    //init
    for(int i = 0; i <= 26; i++) ans.push_back(i);

    while(n--)
    {
        for(int i = 0; i <= 12; i++)
            L.push_back(ans.front()),ans.pop_front();
        for(int i = 13; i <= 26; i++)
            R.push_back(ans.front()),ans.pop_front();

        //input
        int input = 0, idx = 0;
        while(input != 27)
        {
            cin >> A[idx];
            input += A[idx];
            idx++;
        }

        for(int i = 0; i < idx; i++)
        {
            for(int mov = 0; mov < A[i]; mov++)
            {
                if(i % 2)
                {
                    ans.push_back(L.front());
                    L.pop_front();
                }
                else
                {
                    ans.push_back(R.front());
                    R.pop_front();
                }
            }
        }
    }

    for(int i = 0; i <= 26; i++)
        if(ans[i] == 0)
        {
            cout << i+1;
            break;
        }
}

int main()
{
    INPUT();
    SOLVE();
}
