#include <iostream>
#include <string>
#include <algorithm>
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
}


void solution()
{
    while (getline(cin, str))
    {
        if (str == "***") break;

        for (int i = str.length() - 1; i >= 0; i--) cout << str[i];
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}