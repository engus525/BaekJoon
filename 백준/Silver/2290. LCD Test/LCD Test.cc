#include <iostream>
#include <string>
using namespace std;

int s;
string n;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> n;
}

void Head(char c)
{
    cout << " ";
    for(int i = 0; i < s; i++)
    {
        if(c == '1' || c == '4') cout << " ";
        else cout << "-";
    }
    cout << " ";
}
void Face(char c)
{
    if(c=='1'||c=='2'||c=='3'||c=='7') cout << " ";
    else cout << "|";
    for(int i = 0; i < s; i++) cout << " ";
    if(c=='5'||c=='6') cout << " ";
    else cout << "|";
}
void Mid(char c)
{
    cout << " ";
    for(int i = 0; i < s; i++)
    {
        if(c=='1'||c=='7'||c=='0') cout << " ";
        else cout << "-";
    }
    cout << " ";
}
void Leg(char c)
{
    if(c=='2'||c=='6'||c=='8'||c=='0')cout << "|";
    else cout << " ";
    for(int i = 0; i < s; i ++) cout << " ";
    if(c=='2') cout << " ";
    else cout << "|";

}
void Feet(char c)
{
    cout << " ";
    for(int i = 0; i < s; i++)
    {
        if(c=='1'||c=='4'||c=='7') cout << " ";
        else cout << "-";
    }
    cout << " ";
}


void SOLVE()
{
    long long temp = stoll(n);
    n = to_string(temp);

    int row = 2*s+3;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < n.length(); j++)
        {
            if(i == 0) Head(n[j]);
            else if((0 < i) && (i < row/2)) Face(n[j]);
            else if(i == row/2) Mid(n[j]);
            else if((row/2) < i && (i < row-1)) Leg(n[j]);
            else if(i == row-1) Feet(n[j]);
            cout << " ";
        }
        cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}