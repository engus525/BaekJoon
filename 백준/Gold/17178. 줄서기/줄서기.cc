#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<pair<char, int>> v;
vector<pair<char, int>> targetOrder;
stack<pair<char, int>> st;
queue<pair<char, int>> q;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < 5 * n; i++)
    {
        string ticket;
        cin >> ticket;
        char f = ticket[0];
        int b = stoi(ticket.substr(2));
        v.emplace_back(f, b);
    }
}

void solution()
{
    for (auto i : v) q.emplace(i);
    targetOrder = v;
    sort(targetOrder.begin(), targetOrder.end());


    for (int i = 0; i < targetOrder.size(); i++)
    {
        auto target = targetOrder[i];
        //cout << "target : " << target.first << "-" << target.second << '\n';

        if (!st.empty() && st.top() == target) st.pop();
        else if (!q.empty() && q.front() == target) q.pop();
        else if (!q.empty()) st.push(q.front()), q.pop(), i--;
        else break;
    }

    if (q.empty() && st.empty()) cout << "GOOD";
    else cout << "BAD";
}

int main()
{
    INPUT();
    solution();
}