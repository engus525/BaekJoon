#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;

priority_queue<int> pq;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int level;
        cin >> level;
        pq.emplace(level);
    }
}


void solution()
{
    int cut = round(n * 0.3 / 2);
//    cout << "cut : " << cut << '\n';

    for (int i = 0; i < cut; i++) pq.pop();

    int total = 0;
    while (pq.size() > cut) total += pq.top(), pq.pop();

//    cout << "cnt = " << n - cut * 2 << '\n';
    if (n == 0) cout << 0;
    else cout << int(round(double(total) / (n - cut * 2)));
}

int main()
{
    INPUT();
    solution();
}