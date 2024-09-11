#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int a[10], b[10];

void INPUT()
{
    IAMFAST
    for (int i = 0; i < 10; i++) cin >> a[i];
    for (int i = 0; i < 10; i++) cin >> b[i];
}

void solution()
{
    int A = 0, B = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] > b[i]) A++;
        else if (a[i] < b[i]) B++;
    }
    if (A > B) cout << "A";
    else if (A < B) cout << "B";
    else cout << "D";
}

int main()
{
    INPUT();
    solution();
}