#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

double a, b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}


void solution()
{
    if (a / (b * b) > 25) cout << "Overweight";
    else if (a / (b * b) >= 18.5) cout << "Normal weight";
    else if (a / (b * b) < 18.5) cout << "Underweight";
}

int main()
{
    INPUT();
    solution();
}