#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    cin.ignore();
    while(n--)
    {
        string str;
        getline(cin, str);
        if ('a' <= str[0] && str[0] <= 'z') str[0] -= 'a', str[0] += 'A';
        cout << str << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}