#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int n;
string book;
map<string,int> list;

string best;
int Max = 0;
void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> book;
        if(list.find(book) != list.end())
            list[book]++;
        else list.insert({book, 1});

        Max = max(Max, list[book]);
    }
}


void SOLVE()
{
    for(map<string,int>::iterator it = list.begin(); it != list.end(); it++)
    {
        if(it->second == Max)
        {
            cout << it->first;
            break;
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}