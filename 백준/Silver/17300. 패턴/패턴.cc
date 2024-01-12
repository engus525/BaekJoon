#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int pattern[10];
bool visited[10];
void INPUT()
{
    IAMFAST
    cin >> n;
}

void NO()
{
    cout << "NO";
    exit(0);
}

bool blackList(int a, int b)
{
    if (a == 1 && b == 3) return true;
    if (a == 3 && b == 1) return true;
    if (a == 1 && b == 9) return true;
    if (a == 9 && b == 1) return true;
    if (a == 1 && b == 7) return true;
    if (a == 7 && b == 1) return true;

    if (a == 2 && b == 8) return true;
    if (a == 8 && b == 2) return true;

    if (a == 7 && b == 3) return true;
    if (a == 3 && b == 7) return true;
    if (a == 9 && b == 3) return true;
    if (a == 3 && b == 9) return true;

    if (a == 4 && b == 6) return true;
    if (a == 6 && b == 4) return true;

    if (a == 7 && b == 9) return true;
    if (a == 9 && b == 7) return true;

    return false;
}

void solution()
{
    int prev, now = 0;
    while (n--)
    {
        prev = now;
        cin >> now;

        if (visited[now]) NO();
        visited[now] = true;

        if (prev == 0) continue;

        if (!visited[(now + prev) / 2] && blackList(now, prev)) NO();
    }

    cout << "YES";
}

int main()
{
    INPUT();
    solution();
}