#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

int a, b, c;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c;

}

void solution()
{
    cout << a * 3 + b * 4 + c * 5;
}

int main()
{
    INPUT();
    solution();
}