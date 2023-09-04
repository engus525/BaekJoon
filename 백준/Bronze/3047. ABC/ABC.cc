#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int num[3];
string str;

void INPUT()
{
    IAMFAST
    for(int i = 0; i < 3; i++) cin >> num[i];
    cin >> str;
}


void solution()
{
    sort(num, num + 3);
    for (auto &s : str)
    {
        if (s == 'A') cout << num[0] << " ";
        else if (s == 'B') cout << num[1] << " ";
        else if (s == 'C') cout << num[2] << " ";
    }
}

int main()
{
    INPUT();
    solution();
}