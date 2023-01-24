#include <iostream>
#include <algorithm>
using namespace std;

int n;
int li[100001];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> li[i];
}


void SOLVE()
{
    sort(li,li+n);

    int left = 0,right = n-1;
    int sum;

    int ansL,ansR,minGap = 2e9;
    while(left < right)
    {

        sum = li[left] + li[right];

        if(abs(sum) < minGap)
        {
            minGap = abs(sum);
            ansL = li[left];
            ansR = li[right];
        }

        if(sum < 0) left++;
        else if(sum > 0) right--;
        else break;
    }

    cout << ansL << " " << ansR;
}

int main()
{
    INPUT();
    SOLVE();
}