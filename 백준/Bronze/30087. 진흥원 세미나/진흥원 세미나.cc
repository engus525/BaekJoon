#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
map<string, string> M;

void INPUT()
{
    IAMFAST
    cin >> n;
    M.insert({"Algorithm", "204"});
    M.insert({"DataAnalysis", "207"});
    M.insert({"ArtificialIntelligence", "302"});
    M.insert({"CyberSecurity", "B101"});
    M.insert({"Network", "303"});
    M.insert({"Startup", "501"});
    M.insert({"TestStrategy", "105"});
}

void solution()
{
    while (n--)
    {
        string str;
        cin >> str;
        cout << M[str] << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}