#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;

void INPUT()
{
    IAMFAST
    cin >> str;
}

void solution()
{
    cout << ((str[0] == 'E') ? "I" : "E");
    cout << ((str[1] == 'S') ? "N" : "S");
    cout << ((str[2] == 'T') ? "F" : "T");
    cout << ((str[3] == 'P') ? "J" : "P");
}

int main()
{
    INPUT();
    solution();
}