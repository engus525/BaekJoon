#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

double x,y;
int n;
double ans;

void INPUT()
{
    IAMFAST
    cin >> x >> y;
    cin >> n;
}


void solution()
{
    ans = (x/y)*1000;
    while(n--)
    {
        cin >> x >> y;
        ans = min(ans,(x/y)*1000);
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}