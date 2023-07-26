#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

string str;
int visited[30];

void INPUT()
{
    IAMFAST
    getline(cin, str);
}


void solution()
{
    bool flag[4];
    for(auto &s : str)
        if ('A' <= s && s <= 'Z')
        {
            if (s == 'U') visited['U' - 'A']++, flag[0] = true;

            else if (s == 'C' && visited['U' - 'A'])
                visited['C' - 'A']++, flag[1] = true;

            else if (s == 'P' && visited['U' - 'A'] && visited['C' - 'A'])
                visited['P' - 'A']++, flag[2] = true;

            if (s == 'C' && visited['U' - 'A'] && visited['C' - 'A'] && visited['P' - 'A'])
                flag[3] = true;
        }

    bool ans = true;
    for(int i = 0; i < 4; i++)
        if (!flag[i]) ans = false;
    if(ans) cout << "I love UCPC";
    else cout << "I hate UCPC";

}

int main()
{
    INPUT();
    solution();
}