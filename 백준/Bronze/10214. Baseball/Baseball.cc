#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while(t--)
    {
        int sumA = 0, sumB = 0;
        for(int i = 0; i < 9; i++)
        {
            int y, k;
            cin >> y >> k;
            sumA += y;
            sumB += k;
        }
        
        if (sumA > sumB) cout << "Yonsei\n";
        else if (sumA < sumB) cout << "Korea\n";
        else cout << "Draw\n";
    }


}

int main()
{
    INPUT();
    solution();
}