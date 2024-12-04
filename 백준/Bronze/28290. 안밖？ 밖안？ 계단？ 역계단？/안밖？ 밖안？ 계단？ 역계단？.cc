#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

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
    if (str == "fdsajkl;" || str == "jkl;fdsa") cout << "in-out";
    else if (str == "asdf;lkj" || str == ";lkjasdf") cout << "out-in";
    else if (str == "asdfjkl;") cout << "stairs";
    else if (str == ";lkjfdsa") cout << "reverse";
    else cout << "molu";
}

int main()
{
    INPUT();
    solution();
}