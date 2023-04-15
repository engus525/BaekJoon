#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
int li[100001];
int target;
int ans = 0;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++) cin >> li[i];
    cin >> target;
}

void SOLVE()
{
    sort(li,li+n);
    int left = 0, right = n-1;
    while(left < right)
    {
        int sum = li[left]+li[right];
        if(sum == target) ans++,left++;
        else if(sum < target) left++;
        else right--;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}