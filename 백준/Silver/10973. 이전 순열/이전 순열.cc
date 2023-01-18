#include <iostream>
#include <algorithm>
using namespace std;

int n;
int target[10001];


void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> target[i];
}


void SOLVE()
{
    if(prev_permutation(target, target + n))
        for(int i = 0; i < n; i++)
            cout << target[i] << " ";
    else cout << -1;
}

int main()
{
    INPUT();
    SOLVE();
}
