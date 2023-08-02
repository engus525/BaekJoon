#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int l,r;
bool visited[100001];

void INPUT()
{
    IAMFAST
    cin >> l >> r;
}

int g(int num)
{
    int copy = num;
    visited[num] = true;
    while(true)
    {
        string str = to_string(copy);
        int Sum = 0, mul = 1;
        for(auto &s : str) Sum += s - '0', mul *= s - '0';

        string New = to_string(Sum) + to_string(mul);
        if (stoi(New) > 100000) return -1;
        if (str == New) return 1;
        if (visited[stoi(New)]) return 0;
        visited[stoi(New)] = true;
        copy = stoi(New);
    }
}

void solution()
{
    int ans = 0;
    for(int i = l; i <= r; i++)
        memset(visited, false, sizeof visited),
        ans += g(i);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}