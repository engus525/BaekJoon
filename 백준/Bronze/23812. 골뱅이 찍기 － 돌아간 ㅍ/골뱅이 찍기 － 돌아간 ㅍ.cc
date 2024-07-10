#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

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
    for (int j = 0; j < t; j++)
    {
        for (int k = 0; k < t; k++) cout << "@";
        for (int k = 0; k < 3 * t; k++) cout << " ";
        for (int k = 0; k < t; k++) cout << "@";
        cout << '\n';
    }

    for (int j = 0; j < t; j++)
    {
        for (int k = 0; k < t; k++) cout << "@";
        for (int k = 0; k < 3 * t; k++) cout << "@";
        for (int k = 0; k < t; k++) cout << "@";
        cout << '\n';
    }

    for (int j = 0; j < t; j++)
    {
        for (int k = 0; k < t; k++) cout << "@";
        for (int k = 0; k < 3 * t; k++) cout << " ";
        for (int k = 0; k < t; k++) cout << "@";
        cout << '\n';
    }

    for (int j = 0; j < t; j++)
    {
        for (int k = 0; k < t; k++) cout << "@";
        for (int k = 0; k < 3 * t; k++) cout << "@";
        for (int k = 0; k < t; k++) cout << "@";
        cout << '\n';
    }

    for (int j = 0; j < t; j++)
    {
        for (int k = 0; k < t; k++) cout << "@";
        for (int k = 0; k < 3 * t; k++) cout << " ";
        for (int k = 0; k < t; k++) cout << "@";
        cout << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}