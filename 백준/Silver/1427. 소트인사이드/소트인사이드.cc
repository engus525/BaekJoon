#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string n;
vector<char> v;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
}

void SOLVE()
{
    for(int i = 0; i < n.length(); i++)
        v.push_back((n[i]));

    sort(v.rbegin(), v.rend());

    for(int i = 0; i < v.size(); i++)
        cout << v[i];
}

int main()
{
    INPUT();
    SOLVE();
}
