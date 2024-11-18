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

ll xa, xb, ya, yb; // 용체, 용공, 마체, 마공
ll p, s;
bool healed = false;

void INPUT()
{
    IAMFAST
    cin >> xa >> xb >> ya >> yb >> p >> s;
}


void solution()
{
    // 마왕 체력이 P 이하가 되려면 공격해야하는 횟수
    int underP = ceil((ya - p) / (double) xb);
    if (ya - underP * xb > 0) ya += s;

    ll xKo = (ya / xb) + bool(ya % xb);
    ll yKo = (xa / yb) + bool(xa % yb);
//    cout << xKo << " " << yKo << '\n';

    if (xKo <= yKo) cout << "Victory!";
    else cout << "gg";

}

int main()
{
    INPUT();
    solution();
}