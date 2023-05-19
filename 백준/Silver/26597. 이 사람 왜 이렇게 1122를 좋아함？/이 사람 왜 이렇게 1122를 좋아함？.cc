#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // cpp
#include <stdio.h> // c
#include <string>
#include <memory.h> // memset
#include <algorithm>
#include <cmath>
// 자료 구조
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;

#define MAX 1e18
#define MIN -1e18
int q;
vector<pair<long long, char>> Q;
long long start = MIN, last = MAX;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        long long a; char b;
        cin >> a >> b;
        Q.push_back({ a,b });
    }
}



void SOLVE()
{
    int cnt = 0, foundAns = 1e9;
    for(int i = 0; i < Q.size(); i++)
    {
        cnt++;

        long long n = Q[i].first;
        char updown = Q[i].second;

        // 범위 갱신
        if (updown == '^' && start <= n)
            start = n + 1;

        else if (updown == 'v' && last >= n)
            last = n - 1;

        // 모순
        if (start > last)
        {
            cout << "Paradox!\n";
            cout << cnt;
            return;
        }

        if (start == last) foundAns = min(foundAns, cnt);

    }
    // 최애 숫자를 찾았다면
    if (start == last)
    {
        cout << "I got it!\n";
        cout << foundAns;
    }
    else cout << "Hmm...";
}



int main()
{
    INPUT();
    SOLVE();
}

