#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string str;
set<char> S;
int shortCutIdx[31];

void INPUT()
{
    IAMFAST
    cin >> n;
}

bool checkFirstAlphabet(int idx)
{
    for (int i = 0; i < str.length(); i++)
        if (str[i] != ' ')
            if (i == 0 || (str[i - 1] == ' '))
                if (S.find(char(toupper(str[i]))) == S.end())
                {
                    shortCutIdx[idx] = i;
                    S.insert(char(toupper(str[i])));
                    return true;
                }
    return false;
}

void checkAll(int idx)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ') continue;

        if (S.find(char(toupper(str[i]))) == S.end())
        {
            shortCutIdx[idx] = i;
            S.insert(char(toupper(str[i])));
            break;
        }
    }
}

void solution()
{
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        shortCutIdx[i] = -1;
        getline(cin, str);

        if (!checkFirstAlphabet(i))
            checkAll(i);

        for (int j = 0; j < str.length(); j++)
        {
            if (shortCutIdx[i] == j) cout << "[";
            cout << str[j];
            if (shortCutIdx[i] == j) cout << "]";
        }
        cout << '\n';
    }
}


int main()
{
    INPUT();
    solution();
}