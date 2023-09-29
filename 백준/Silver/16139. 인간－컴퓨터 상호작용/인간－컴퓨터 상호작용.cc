#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;
int t;
int ps[27][200001];

void INPUT()
{
    IAMFAST
    cin >> str >> t;
}


void solution()
{
    ps[str[0] - 'a'][0] = 1;
    for (int i = 1; i < str.length(); i++)
    {
        ps[str[i] - 'a'][i]++;
        for (int j = 0; j < 26; j++) ps[j][i] += ps[j][i - 1];
    }

    while (t--)
    {
        char c;
        int s, e;
        cin >> c >> s >> e;
        if (s == 0) cout << ps[c - 'a'][e] << '\n';
        else cout << ps[c - 'a'][e] - ps[c - 'a'][s - 1] << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}