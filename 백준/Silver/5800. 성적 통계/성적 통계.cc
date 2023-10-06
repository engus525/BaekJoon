#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
int score[51];

void INPUT()
{
    IAMFAST
    cin >> t;
}



void solution()
{
    for (int i = 1; i <= t; i++)
    {
        int n; cin >> n;
        for (int s = 0; s < n; s++) cin >> score[s];

        sort(score, score + n);
        int lg = 0;
        for (int s = 0; s < n - 1; s++) lg = max(lg, score[s + 1] - score[s]);

        cout << "Class " << i << '\n';
        cout << "Max " << score[n-1] << ", Min " << score[0] << ", Largest gap " << lg << '\n';

    }
}

int main()
{
    INPUT();
    solution();
}