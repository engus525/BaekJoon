#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <memory.h>
#include <map>
#include <algorithm>

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

void solution()
{
    cout << "The largest square has side length " << int(sqrt(n)) << ".";
}

int main()
{
    INPUT();
    solution();
}