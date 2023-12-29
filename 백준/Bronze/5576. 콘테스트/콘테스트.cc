#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

priority_queue<int> W,K;

void INPUT()
{
    IAMFAST
}

void solution()
{
    for (int i = 0; i < 10; i++)
    {
        int w; cin >> w;
        W.emplace(w);
    }
    for (int i = 0; i < 10; i++)
    {
        int k; cin >> k;
        K.emplace(k);
    }

    int sumW = 0, sumK = 0;
    for (int i = 0; i < 3; i++) sumW += W.top(), W.pop(), sumK += K.top(), K.pop();
    cout << sumW << " " << sumK;
}

int main()
{
    INPUT();
    solution();
}