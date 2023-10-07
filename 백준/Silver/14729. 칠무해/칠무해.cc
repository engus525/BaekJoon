#include <iostream>
#include <queue>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
priority_queue<double, vector<double>, greater<double>> pq;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double score; cin >> score;
        pq.emplace(score);
    }
}



void solution()
{
    cout << fixed; cout.precision(3);
    for (int i = 0; i < 7; i++)
        cout << pq.top() << "\n", pq.pop();
}

int main()
{
    INPUT();
    solution();
}