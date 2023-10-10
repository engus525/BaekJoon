#include <iostream>
#include <string>
#include <set>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
char game;
set<string> S;
int cnt = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> game;
    for (int i = 0; i < n; i++)
    {
        string name; cin >> name;
        if (S.find(name) == S.end()) S.emplace(name), cnt++;
    }
}

void solution()
{
    if (game == 'Y') cout << cnt;
    else if (game == 'F') cout << cnt / 2;
    else if (game == 'O') cout << cnt / 3;
}

int main()
{
    INPUT();
    solution();
}