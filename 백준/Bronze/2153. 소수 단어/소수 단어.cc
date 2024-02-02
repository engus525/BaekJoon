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
    cin >> str;
}

void solution()
{
    int total = 0;
    for (auto s : str)
    {
        if ('a' <= s && s <= 'z') total += s - 'a' + 1;
        else total += s - 'A' + 27;
    }

    bool isNotPrime = false;
    for (int i = 2; i * i <= total; i++)
        if (total % i == 0)
        {
            isNotPrime = true;
            break;
        }
    
    if (isNotPrime) cout << "It is not a prime word.";
    else cout << "It is a prime word.";
}

int main()
{
    INPUT();
    solution();
}