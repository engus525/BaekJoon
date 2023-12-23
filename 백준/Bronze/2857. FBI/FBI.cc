#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;

void INPUT()
{
    IAMFAST
}


void solution()
{
    bool fbi = false;
    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
            if (str[j] == 'F' && str[j + 1] == 'B' && str[j + 2] == 'I')
            {
                cout << i + 1 << " ", fbi = true;
                break;
            }
    }

    if (!fbi) cout << "HE GOT AWAY!";
}

int main()
{
    INPUT();
    solution();
}