#include <iostream>
#include <string>
#include <numeric>

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
    string temp_n, temp_m;

    int cri_idx = 0;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ':') cri_idx = i;

    temp_n = str.substr(0, cri_idx);
    temp_m = str.substr(cri_idx + 1, str.length() - cri_idx - 1);

    int n = stoi(temp_n), m = stoi(temp_m);
    int GCD = gcd(n, m);

    cout << n / GCD << ":" << m / GCD;
}

int main()
{
    INPUT();
    solution();
}