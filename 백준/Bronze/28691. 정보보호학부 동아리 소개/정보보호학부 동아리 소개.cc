#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string n;
map<string , string> M;

void INPUT()
{
    IAMFAST
    cin >> n;
    M.insert({"M", "MatKor"});
    M.insert({"W", "WiCys"});
    M.insert({"C", "CyKor"});
    M.insert({"A", "AlKor"});
    M.insert({"$", "$clear"});
    M.insert({"Startup", "501"});
}

void solution()
{
    cout << M[n];
}

int main()
{
    INPUT();
    solution();
}