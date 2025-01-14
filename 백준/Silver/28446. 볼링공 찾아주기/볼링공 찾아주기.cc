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
typedef pair<long long, long long> pll;

int n;
map<int, int> M;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int box, w; cin >> box >> w;
            M[w] = box;
        }
        else
        {
            int w; cin >> w;
            cout << M[w] << '\n';
        }
    }
}


int main()
{
    INPUT();
    solution();
}