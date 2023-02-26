#include <iostream>
#include <string>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int tc;
int n;

string number[10] = {"","",
                   "1","7",
                   "4","2",
                   "6","8"};
string minDP[101] , maxDP[101];

void INPUT()
{
    IAMFAST
    cin >> tc;
}

string MIN(string a,string b)
{
    if(a.length() == b.length())
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] < b[i]) return a;
            else if(a[i] > b[i]) return b;
            else continue;
        }
    if(a.length() < b.length()) return a;
    else return b;
}

void SOLVE()
{
    //Init
    minDP[1] = "1"; maxDP[1] = "";
    for(int i = 2; i <= 7; i++)
    {
        minDP[i] = number[i];
        if(i % 2 == 0) maxDP[i] = maxDP[i-1] + "1" , maxDP[i][0] = '1';
        else maxDP[i] = maxDP[i-1] , maxDP[i][0] = '7';
    }

    for(int i = 8; i <= 100; i++)
    {
        minDP[i] = "99999999999999999999";
        for(int j = 2; j <= 7; j++)
        {
            string add = number[j];
            if(add == "6") add = "0";
            minDP[i] = MIN(minDP[i],minDP[i - j] + add);

            if(i % 2 == 0) maxDP[i] = maxDP[i-1] + "1" , maxDP[i][0] = '1';
            else maxDP[i] = maxDP[i-1] , maxDP[i][0] = '7';
        }
    }

    while(tc--)
    {
        cin >> n;
        cout << minDP[n] << " " << maxDP[n] << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}