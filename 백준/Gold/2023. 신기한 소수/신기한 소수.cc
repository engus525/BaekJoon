#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int n;

void INPUT()
{
    IAMFAST
    cin >> n;
}

bool canFirst(int num)
{
    return (num == 2 || num == 3 || num == 5 || num == 7);
}
bool canLast(int num)
{
    return (num % 2);
}

bool isPrime(int num)
{
    for(int i = 2; i*i <= num; i++)
        if (num % i == 0) return false;
    return true;
}

void setComb(int depth, int prime)
{
    if (n == 1)
    {
        cout << 2 << '\n' << 3 << '\n' << 5 << '\n' << 7 << '\n';
        return;
    }
    if (to_string(prime).length() == n)
    {
        cout << prime << '\n';
        return;
    }

    for(int i = 1; i <= 9; i++)
    {
        if (depth == 0 && !canFirst(i)) continue;
        else if (depth == n - 1 && !canLast(i)) continue;

        int temp = prime * 10 + i;
        if (!isPrime(temp)) continue;
        setComb(depth + 1, temp);
    }
}

void solution()
{
    setComb(0, 0);
}

int main()
{
    INPUT();
    solution();
}