#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string a,b;

void INPUT()
{
    IAMFAST
    cin >> a >> b;
}

void SOLVE()
{
    int aView,bView;
    for(int i = 0; i < a.length(); i++)
    {
        bool found = false;
        for (int j = 0; j < b.length(); j++)
            if (a[i] == b[j])
            {
                aView = i;//행
                bView = j;//열
                found = true;
                break;
            }
        if(found) break;
    }

    for(int i = 0; i < b.length(); i++)
    {
        if(bView == i)
        {
            cout << a << '\n';
            continue;
        }

        for(int j = 0 ; j < a.length(); j++)
        {
            if(aView == j) cout << b[i];
            else cout << ".";
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}