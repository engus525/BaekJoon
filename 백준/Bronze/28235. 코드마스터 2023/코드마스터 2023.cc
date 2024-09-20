#include <iostream>
#include <algorithm>

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
    if (str == "SONGDO") cout << "HIGHSCHOOL";
    else if (str == "CODE") cout << "MASTER";
    else if (str == "2023") cout << "0611";
    else if (str == "ALGORITHM") cout << "CONTEST";
}

int main()
{
    INPUT();
    solution();
}