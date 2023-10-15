#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int A[10], B[10];

void INPUT()
{
    IAMFAST
    for (int i = 1; i <= 9; i++) cin >> A[i];
    for (int i = 1; i <= 9; i++) cin >> B[i];
}

void solution()
{
    int a_sum = 0, b_sum = 0;

    bool winning = false;
    for (int i = 1; i <= 18; i++)
    {
        if (i % 2) a_sum += A[(i+1)/2];
        else b_sum += B[i/2];

        if (a_sum > b_sum) winning = true;
    }

    if (winning && a_sum < b_sum) cout << "Yes";
    else cout << "No";
}

int main()
{
    INPUT();
    solution();
}