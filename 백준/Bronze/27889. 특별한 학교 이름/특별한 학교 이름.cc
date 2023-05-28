#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str;

void INPUT()
{
    IAMFAST
    cin >> str;
}


void SOLVE()
{
   if(str == "NLCS") cout << "North London Collegiate School";
   else if(str == "BHA") cout << "Branksome Hall Asia";
   else if(str == "KIS") cout << "Korea International School";
   else cout << "St. Johnsbury Academy";
}

int main()
{
    INPUT();
    SOLVE();
}