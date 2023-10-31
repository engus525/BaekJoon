#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
struct COUNTRY
{
    int id;
    int g, s, b;
    int rank = 0;
};

bool comp(COUNTRY a, COUNTRY b)
{
    if (a.g == b.g)
    {
        if (a.s == b.s)
        {
            if (a.b == b.b) return a.b == b.b;
            else return a.b > b.b;
        } else return a.s > b.s;
    } else return a.g > b.g;
}
bool operator==(COUNTRY a, COUNTRY b)
{
    if (a.g == b.g && a.s == b.s && a.b == b.b) return true;
    else return false;
}

vector<COUNTRY> v;

void INPUT()
{
    IAMFAST
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int id, g, s, b;
        cin >> id >> g >> s >> b;
        v.push_back({id, g, s, b});
    }
}


void solution()
{
    sort(v.begin(), v.end(), comp);

    int r = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i].rank) continue;

        v[i].rank = r;
        int passed = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] == v[j]) v[j].rank = r, passed++;
            else break;
        }
        r += passed;
    }

    for (auto c : v)
    {
        if (c.id == k)
        {
            cout << c.rank;
            break;
        }
    }
}

int main()
{
    INPUT();
    solution();
}