#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <stack>
#include <cmath>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int cnt[10000001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        if (cnt[num])
        {
            cout << num;
            return;
        }
        cnt[num]++;
    }
}


void solution()
{

}

int main()
{
    INPUT();
    solution();
}