#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
string str;

void INPUT()
{
    IAMFAST
    cin >> n;
}

void solution()
{
    while (n--)
    {
        cin >> str; int strlen = str.length();
        if (str.back() == 'a') str.pop_back(), str += "as";
        else if (str.back() == 'l') str.pop_back(), str += "les";
        else if (str.back() == 'o') str.pop_back(), str += "os";
        else if (str.back() == 'r') str.pop_back(), str += "res";
        else if (str.back() == 't') str.pop_back(), str += "tas";
        else if (str.back() == 'u') str.pop_back(), str += "us";
        else if (str.back() == 'v') str.pop_back(), str += "ves";
        else if (str.back() == 'w') str.pop_back(), str += "was";
        else if (str.back() == 'i' || str.back() == 'y') str.pop_back(), str += "ios";
        else if (str.back() == 'n') str.pop_back(), str += "anes";

        else if (str.length() >= 2 && str[strlen - 2] == 'n' && str[strlen - 1] == 'e')
            str.pop_back(), str.pop_back(), str += "anes";
        else str += "us";

        cout << str << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}