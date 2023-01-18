#include <iostream>
#include <string>
using namespace std;

string name;
int age,kg;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}


void SOLVE()
{
    while(cin >> name >> age >> kg)
    {
        if(name == "#") break;

        cout << name << " ";
        if(age > 17 || kg >= 80) cout << "Senior\n";
        else cout << "Junior\n";
    }
}

int main()
{
    INPUT();
    SOLVE();
}