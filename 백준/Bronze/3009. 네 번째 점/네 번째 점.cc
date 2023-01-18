#include <iostream>
#include <map>
using namespace std;

map<int, int> x, y;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 3; i++)
    {
        int a, b; cin >> a >> b;
        if(x.find(a) == x.end()) x.insert({a, 1});
        else x[a]++;
        if(y.find(b) == y.end()) y.insert({b, 1});
        else y[b]++;

    }
}

void SOLVE()
{
    map<int, int>::iterator it;
    for(it = x.begin(); it != x.end(); it++)
        if (it->second == 1) cout << it->first;

    cout << " ";

    for(it = y.begin(); it != y.end(); it++)
        if (it->second == 1) cout << it->first;
}

int main()
{
    INPUT();
    SOLVE();
}
