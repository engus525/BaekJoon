#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;

void INPUT()
{
    IAMFAST
    getline(cin, str);
}

void solution()
{
    if (str[0] == str[str.length() - 1] && str[0] == '\"' && str.length() > 2) cout << str.substr(1, str.length() - 2);
    else cout << "CE";
}

int main()
{
    INPUT();
    solution();
}