#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string name, status, history;
int best, grade;
vector<pair<int, string>> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> status >> history >> best >> grade;
        if (status != "jaehak") continue;
        if (history == "winner") continue;
        if (best > 0 && best <= 3) continue;
        v.emplace_back(grade, name);
    }
}


void solution()
{
    sort(v.begin(), v.end());
    vector<string> winner;
    for (int i = 0; i < v.size() && i < 10; i++) winner.emplace_back(v[i].second);
    sort(winner.begin(), winner.end());
    cout << winner.size() << '\n';
    for (string name : winner) cout << name << '\n';

}

int main()
{
    INPUT();
    solution();
}