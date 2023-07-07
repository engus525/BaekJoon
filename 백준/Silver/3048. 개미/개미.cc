#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m;
bool in1[30];
string ant1;
string ant2;
int t;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    cin >> ant1 >> ant2;
    cin >> t;
}


void SOLVE()
{
    reverse(ant1.begin(), ant1.end());
    for(auto &a : ant1) in1[a-'A'] = true;

    string ant = ant1 + ant2;
    while(t--)
    {
        for(int i = 0; i < ant.length()-1; i++)
            if(in1[ant[i]-'A'] && !in1[ant[i+1]-'A'])
                swap(ant[i],ant[i+1]), i++;
    }
    cout << ant;
}

int main()
{
    INPUT();
    SOLVE();
}