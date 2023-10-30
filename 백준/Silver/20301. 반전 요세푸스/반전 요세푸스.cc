#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k, m;
vector<int> v(5001);
bool visited[5001];
int deleted = 0, dir = 1, idx = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) v[i] = i;
}

void moveIdx()
{
    idx += dir;
    if (idx == 0) idx = n;
    else if (idx == n + 1) idx = 1;
}

void moveK()
{
    int cnt = k;
    while (cnt)
    {
        moveIdx();
        while(visited[idx]) moveIdx();
        cnt--;
    }

}

void deletePerson()
{
    cout << v[idx] << "\n";
    visited[idx] = true;
    deleted++;
}

void solution()
{

    while (true)
    {
        if (deleted == n) break;
        if (deleted && deleted % m == 0) dir *= -1;

        moveK();
        deletePerson();
    }
}

int main()
{
    INPUT();
    solution();
}