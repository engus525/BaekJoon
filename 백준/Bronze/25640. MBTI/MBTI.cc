#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string str;
int n;

void INPUT()
{
    IAMFAST
    cin >> str >> n;
}

void solution()
{
    int ans = 0;
    while(n--)
    {
        string mbti; cin >> mbti;
        if (str == mbti) ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}