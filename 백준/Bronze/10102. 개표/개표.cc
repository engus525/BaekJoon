#include <iostream>
#include <string>

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
    int a_cnt = 0;
    for(auto &s : str)
        if (s == 'A') a_cnt++;

    if (a_cnt > n - a_cnt) cout << "A";
    else if (a_cnt < n - a_cnt) cout << "B";
    else cout << "Tie";
}

int main()
{
    INPUT();
    solution();
}