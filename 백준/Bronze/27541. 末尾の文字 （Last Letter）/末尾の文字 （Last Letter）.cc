#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string str;

void INPUT()
{
    IAMFAST
    cin >> n >> str;
}

void solution()
{
    if (str.back() == 'G') str.pop_back();
    else str += 'G';
    cout << str;
}

int main()
{
    INPUT();
    solution();
}