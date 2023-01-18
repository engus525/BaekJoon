#include <iostream>
#include <string>
using namespace std;

string word;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> word;
}

void SOLVE()
{
    int ans = 0;

    for(int i = 0; i < word.length(); i++)
    {
        char c = word[i];

        if (c <= 'C') ans += 2;
        else if (c <= 'F') ans += 3;
        else if (c <= 'I') ans += 4;
        else if (c <= 'L') ans += 5;
        else if (c <= 'O') ans += 6;
        else if (c <= 'S') ans += 7;
        else if (c <= 'V') ans += 8;
        else if (c <= 'Z') ans += 9;

    }
    ans += word.length();

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
