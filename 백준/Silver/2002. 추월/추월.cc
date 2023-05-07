#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
unordered_map<string,int> M;
int out[1001];
string id;

void INPUT()
{
    IAMFAST
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> id;
        M.insert({id, i});
    }
}


void SOLVE()
{
    int ans = 0;

    for(int i = 0; i < n; i++) cin >> id, out[i] = M[id];

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
            if(out[i] > out[j])
            {
                ans++;
                break;
            }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}