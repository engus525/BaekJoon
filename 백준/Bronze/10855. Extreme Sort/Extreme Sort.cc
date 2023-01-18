#include <iostream>
using namespace std;

int n;
int list[1025];

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> list[i];
}


void SOLVE()
{
    bool isAscending = true;
    for(int i = 1; i < n; i++)
        if(list[i] < list[i - 1])
        {
            isAscending = false;
            break;
        }
    if(isAscending) cout << "yes";
    else cout << "no";
}

int main()
{
    INPUT();
    SOLVE();
}
