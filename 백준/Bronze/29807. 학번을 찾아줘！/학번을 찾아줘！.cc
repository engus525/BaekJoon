#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
int score[5];

void INPUT()
{
    IAMFAST
    cin >> t;
    for (int i = 0; i < t; i++) cin >> score[i];
}

void solution()
{
    int id = 0;
    if (score[0] > score[2]) id = 508 * (score[0] - score[2]);
    else id = 108 * (score[2] - score[0]);

    if (score[1] > score[3]) id += 212 * (score[1] - score[3]);
    else id += 305 * (score[3] - score[1]);

    if (t == 5) id += 707 * score[4];

    id *= 4763;

    cout << id;
}

int main()
{
    INPUT();
    solution();
}