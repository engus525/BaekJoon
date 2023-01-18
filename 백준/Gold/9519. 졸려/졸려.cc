#include <iostream>
#include <string>
#include <stack>
using namespace std;

int x;
string origin,change;
int len;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x >> origin;
    len = origin.length();
    change = origin;
}

bool Move()
{
    stack<char> st;
    int cnt = (len-1)/2;
    bool isOdd = false;
    for(int i = 0; cnt; i++)
    {
        if(isOdd)
        {
            isOdd = false;
            st.push(change[i]);
            change.erase(change.begin() + i);
            i--;
            cnt--;
        }
        else isOdd = true;
    }
    while(!st.empty()) change += st.top(),st.pop();

    return origin == change;
}

void SOLVE()
{

    int cycle = 0;
    while(true)
    {
        cycle++;
        if(Move()) break;

    }
    x %= cycle;

    for(int i = 0; i < x; i++) Move();
    cout << change;


}

int main()
{
    INPUT();
    SOLVE();
}