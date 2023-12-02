#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
vector<int> v;
stack<int> st;

void INPUT()
{
    IAMFAST
    cin >> n;

}


void solution()
{
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;

        while (num--) st.push(v.back()), v.pop_back();
        v.emplace_back(i);
        while (!st.empty()) v.emplace_back(st.top()), st.pop();
    }

    for (auto &i : v) cout << i << " ";
}

int main()
{
    INPUT();
    solution();
}