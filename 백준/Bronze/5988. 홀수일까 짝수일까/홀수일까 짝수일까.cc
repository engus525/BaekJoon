#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;

void INPUT()
{
    IAMFAST
    cin >> t;
}


void solution()
{
    while (t--)
    {
        string str; cin >> str;
        int last = str.back() - '0';

        if (last % 2) cout << "odd\n";
        else cout << "even\n";
    }
}

int main()
{
    INPUT();
    solution();
}