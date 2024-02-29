#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int pos[125];
stack<int> A, B;
queue<pii> q;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v; cin >> v;
        A.emplace(v);
    }
}

void solution()
{
    for (int i = 1; i <= n; i++) pos[i] = 1;

    int todo = n;
    while (!A.empty() || !B.empty() || todo)
    {
        if (pos[todo] == 1)
        {
            while (A.top() != todo)
            {
                q.emplace(1, 2);
                B.emplace(A.top());
                pos[A.top()] = 2;
                A.pop();
            }
            q.emplace(1, 3);
            A.pop();
        }
        else if (pos[todo] == 2)
        {
            while (B.top() != todo)
            {
                q.emplace(2, 1);
                A.emplace(B.top());
                pos[A.top()] = 1;
                B.pop();
            }
            q.emplace(2, 3);
            B.pop();
        }

        todo--;
    }

    cout << q.size() << '\n';
    while (!q.empty())
        cout << q.front().first << " " << q.front().second << '\n', q.pop();
}

int main()
{
    INPUT();
    solution();
}