#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n,m;
bool comp(pair<string,int> &a, pair<string,int> &b)
{
    if(a.second == b.second)
    {
        if(a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    else return a.second > b.second;
}
map<string,int> words;


void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string word; cin >> word;
        if(word.length() < m) continue;
        else words[word]++;
    }
}


void SOLVE()
{
    vector<pair<string, int>> v(words.begin(), words.end());
    sort(v.begin(), v.end(),comp);

    for(auto &i : v)
    {
        cout << i.first << "\n";
    }
}

int main()
{
    INPUT();
    SOLVE();
}