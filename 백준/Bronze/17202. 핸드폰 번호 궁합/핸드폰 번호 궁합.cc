#include <iostream>
#include <string>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string A,B;
string AB = "";

void INPUT()
{
    IAMFAST
    cin >> A >> B;
}

void SOLVE()
{
    for(int i = 0; i < A.length(); i++)
        AB += A[i], AB += B[i];

    while(AB.length() > 2)
    {
        for(int i = 0; i < AB.length()-1; i++)
            AB[i] = (int((AB[i]-'0')+(AB[i+1]-'0')) % 10) + '0';
        AB.pop_back();
    }
    cout << AB;
}

int main()
{
    INPUT();
    SOLVE();
}