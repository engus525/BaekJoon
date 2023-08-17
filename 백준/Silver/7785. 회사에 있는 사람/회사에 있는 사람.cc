#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
map<string,string> Map;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string name, status;
        cin >> name >> status;
        Map[name] = status;
    }
}


void solution()
{
    vector<pair<string,string>> v;

    for (auto [name, status] : Map)
        v.emplace_back(name,status);
    sort(v.rbegin(), v.rend());

    for (auto [name, status] : v)
        if (status == "enter")
            cout << name << '\n';
}

int main()
{
    INPUT();
    solution();
}