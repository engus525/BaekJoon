#include <iostream>
#include <deque>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n, t;
deque<char> dq[1001];
int idx, dir;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (char s: str)
            dq[i].push_back(s);
    }
    cin >> t;
}

void Rotate(int i, int &d)
{
    if (d == 1) dq[i].push_front(dq[i].back()), dq[i].pop_back();
    else dq[i].push_back(dq[i].front()), dq[i].pop_front();
    if (i != idx) d *= -1;
}

void left()
{
    if (idx == 1) return;

    int lastIdx = idx;
    char cri = dq[lastIdx][6];
    while (lastIdx > 1)
    {
        if (cri == dq[lastIdx - 1][2]) break;
        cri = dq[lastIdx - 1][6];
        lastIdx--;
    }

    int d = -dir;
    for (int i = idx - 1; i >= lastIdx; i--) Rotate(i, d);
}

void right()
{
    if (idx == n) return;


    int lastIdx = idx;
    char cri = dq[lastIdx][2];
    while (lastIdx < n)
    {
        if (cri == dq[lastIdx + 1][6]) break;
        cri = dq[lastIdx + 1][2];
        lastIdx++;
    }

    int d = -dir;
    for (int i = idx + 1; i <= lastIdx; i++) Rotate(i, d);
}

void solution()
{
    while (t--)
    {
        cin >> idx >> dir;

        left();
        right();

        Rotate(idx, dir);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dq[i][0] == '1') ans++;
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}