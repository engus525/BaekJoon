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
string channel[101];
int kbs1, kbs2;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> channel[i];
        if (channel[i] == "KBS1") kbs1 = i;
        else if (channel[i] == "KBS2") kbs2 = i;
    }
}

void solution()
{
    for (int i = 0; i < kbs1; i++) cout << 1;
    for (int i = 0; i < kbs1; i++) cout << 4;
    if (kbs2 < kbs1) kbs2++;
    for (int i = 0; i < kbs2; i++) cout << 1;
    for (int i = 0; i < kbs2 - 1; i++) cout << 4;
}

int main()
{
    INPUT();
    solution();
}