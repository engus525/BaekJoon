#include <iostream>
#include <map>
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
    int num;
    while (cin >> num)
    {
        if (!num) break;

        if (num % n) cout << num << " is NOT a multiple of " << n << ".\n";
        else cout << num << " is a multiple of " << n << ".\n";


    }
}

int main()
{
    INPUT();
    solution();
}