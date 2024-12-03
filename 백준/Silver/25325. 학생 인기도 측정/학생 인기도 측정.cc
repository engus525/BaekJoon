#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
map<string, int> M;
vector<pair<string, int>> v;

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.emplace_back(str, 0);
        M.emplace(str, 0);
    }
}

void solution()
{
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        string name;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == ' ')
            {
                M[name]++, name = "";
            } else name += str[j];
        }
        M[name]++;
    }
    for (auto &data: v)
    {
        data.second = M[data.first];
    }

    sort(v.begin(), v.end(), [](auto a, auto b)
    {
        if (a.second == b.second) return a.first < b.first;
        else return a.second > b.second;
    });

    for (auto data: v) cout << data.first << " " << data.second << '\n';
}

int main()
{
    INPUT();
    solution();
}