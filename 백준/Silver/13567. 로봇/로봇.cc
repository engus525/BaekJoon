#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, d;
string str;
pii dir[4] = {{1,  0},
              {0,  -1},
              {-1,  0},
              {0, 1}};
pii now = {0, 0};
int nd = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
}

void Move()
{
    now.first += dir[nd].first * d;
    now.second += dir[nd].second * d;
}

void Turn()
{
    if (d) nd = (nd + 1) % 4;
    else nd = (nd - 1 + 4) % 4;
}

void solution()
{
    while (m--)
    {
        cin >> str >> d;
        if (str == "MOVE") Move();
        else Turn();

        if (now.first < 0 || now.first > n || now.second < 0 || now.second > n)
        {
            cout << -1;
            return;
        }
    }
    cout << now.first << " " << now.second;
}

int main()
{
    INPUT();
    solution();
}