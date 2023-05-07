#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int k,l;
vector<string> v;
unordered_map<string,int> M;
string id;

void INPUT()
{
    IAMFAST
    cin >> k >> l;
}


void SOLVE()
{
    while(l--)
    {
        cin >> id;
        if(M.find(id) != M.end()) M[id]++;
        else M.insert({id, 1});
        v.push_back(id);
    }

    int cnt = 0;
    for(auto i : v)
    {
        if(cnt >= k) break;

        if(M[i] == 1) cout << i << '\n', cnt++;
        else M[i]--;
    }
}

int main()
{
    INPUT();
    SOLVE();
}