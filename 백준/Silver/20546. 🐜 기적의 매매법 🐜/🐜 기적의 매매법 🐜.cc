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

int money1, money2;
int stock[15];

void INPUT()
{
    IAMFAST
    cin >> money1; money2 = money1;
    for(int i = 1; i <= 14; i++) cin >> stock[i];
}

void solution()
{
    int jh = 0, sm = 0;

    int up = 1, down = 1;
    for(int i = 1; i <= 14; i++)
    {
        if (money1 >= stock[i])
            jh += money1 / stock[i],
            money1 -= (money1 / stock[i]) * stock[i];

        if (i > 1 && stock[i-1] < stock[i]) up++, down = 0;
        else if (i > 1 && stock[i-1] > stock[i]) down++, up = 0;

        if (up >= 3) money2 += sm * stock[i], sm = 0;
        else if (down >= 3)
            sm += money2 / stock[i],
            money2 -= (money2 / stock[i]) * stock[i];
    }

    int JH = money1 + stock[14] * jh;
    int SM = money2 + stock[14] * sm;

    if (JH > SM) cout << "BNP";
    else if (JH < SM) cout << "TIMING";
    else cout << "SAMESAME";
}

int main()
{
    INPUT();
    solution();
}