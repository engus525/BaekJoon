#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string object;
double score;
string grade;

void INPUT()
{
    IAMFAST
}

double Grade(string str)
{
    if(str=="A+") return 4.5;
    if(str=="A0") return 4.0;
    if(str=="B+") return 3.5;
    if(str=="B0") return 3.0;
    if(str=="C+") return 2.5;
    if(str=="C0") return 2.0;
    if(str=="D+") return 1.5;
    if(str=="D0") return 1.0;
    if(str=="F") return 0.0;
}


void SOLVE()
{
    double personal = 0;
    double total = 0;
    for(int i = 0; i < 20; i++)
    {
        cin >> object >> score >> grade;
        if(grade=="P") continue;
        personal += score*Grade(grade);
        total += score;
    }
    cout << fixed; cout.precision(10);
    cout << personal/total;
}

int main()
{
    INPUT();
    SOLVE();
}