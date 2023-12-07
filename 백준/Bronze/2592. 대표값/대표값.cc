#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

map<int, int> M;

void INPUT()
{
    IAMFAST
}


void solution()
{
    int sum = 0;
    int mostCnt = 0, mostNum = 0;
    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;

        sum += num;

        if (M.find(num) == M.end()) M.insert({num, 1});
        else M[num]++;

        if (mostCnt < M[num]) mostCnt = M[num], mostNum = num;
    }

    cout << sum / 10 << '\n' << mostNum;
}

int main()
{
    INPUT();
    solution();
}