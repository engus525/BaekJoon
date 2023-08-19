#include <iostream>
#include <map>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, x, y;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    int Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, AXIS = 0;

    while(n--)
    {
        cin >> x >> y;
        if (x > 0 && y > 0) Q1++;
        else if (x < 0 && y > 0) Q2++;
        else if (x < 0 && y < 0) Q3++;
        else if (x > 0 && y < 0) Q4++;
        else AXIS++;
    }

    cout << "Q1: " << Q1 << '\n';
    cout << "Q2: " << Q2 << '\n';
    cout << "Q3: " << Q3 << '\n';
    cout << "Q4: " << Q4 << '\n';
    cout << "AXIS: " << AXIS;
}

int main()
{
    INPUT();
    solution();
}