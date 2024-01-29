#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;

void INPUT()
{
    IAMFAST
    getline(cin,str);
}

void solution()
{
    
    if ((str[0] - '0') + (str[4] - '0') == stoi(str.substr(8))) cout << "YES";
    else cout << "NO";
}

int main()
{
    INPUT();
    solution();
}