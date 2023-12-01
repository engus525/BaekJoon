#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
stack<int> st;
deque<int> q;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        q.push_back(num);
    }
}


void solution()
{
    int need = 1;
    while (!q.empty() || !st.empty())
    {
        if (!q.empty() && q.front() == need) q.pop_front(), need++;
        else if (!st.empty() && st.top() == need) st.pop(), need++;
        else if (!q.empty()) st.push(q.front()), q.pop_front();
        else break;
    }

    if (q.empty() && st.empty()) cout << "Nice";
    else cout << "Sad";
}

int main()
{
    INPUT();
    solution();
}