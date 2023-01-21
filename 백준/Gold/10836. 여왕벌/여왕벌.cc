#include <iostream>
#include <algorithm>
using namespace std;

int m,n;
int map[701+701];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
}

void growFirst(int x,int y,int z)
{
    for(int i = 0; i < 2*m-1; i++)
    {
        if(x) x--;
        else if(y) map[i]++, y--;
        else map[i] += 2, z--;
    }
}



void SOLVE()
{
    while(n--)
    {
        int a,b,c; cin >> a >> b >> c;
        growFirst(a,b,c);
    }

    for(int i = 0; i < m; i++)
    {
        cout << map[m-1-i] + 1 << " ";
        for(int j = m; j < 2*m-1; j++)
            cout << map[j] + 1 << " ";
        cout << '\n';
    }


}

int main()
{
    INPUT();
    SOLVE();
}
