#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
queue<int> q;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    while (t--)
    {
        string str;
        cin >> str;
        int num;
        if (str == "push") cin >> num, q.emplace(num);
        else if (str == "front") (q.empty()) ? cout << -1 << '\n' : cout << q.front() << '\n';
        else if (str == "size") cout << q.size() << '\n';
        else if (str == "pop")
        {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n', q.pop();
        }
        else if (str == "empty") cout << q.empty() << '\n';
        else if (str == "back") (q.empty()) ? cout << -1 << '\n' : cout << q.back() << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}