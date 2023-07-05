#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int l,c;
vector<char> v;
bool visited[16];

void INPUT()
{
    IAMFAST
    cin >> l >> c;
    for(int i = 0; i < c; i++)
    {
        char alpha; cin >> alpha;
        v.emplace_back(alpha);
    }
}

bool isAEIOU(char al)
{
    return (al=='a'||al=='e'||al=='i'||al=='o'||al=='u');
}

void printAns()
{
    string ans;
    int cnt = 0;
    for(int i = 0; i < c; i++)
        if(visited[i])
        {
            if(isAEIOU(v[i])) cnt++;
            ans += v[i];
        }

    if(cnt && l-cnt >= 2) cout << ans << '\n';
}

void setComb(int depth, int start)
{
    if(depth == l)
    {
        printAns();
        return;
    }

    for(int i = start; i < c; i++)
    {
        visited[i] = true;
        setComb(depth+1,i+1);
        visited[i] = false;
    }
}

void SOLVE()
{
    sort(v.begin(),v.end());

    setComb(0,0);
}

int main()
{
    INPUT();
    SOLVE();
}