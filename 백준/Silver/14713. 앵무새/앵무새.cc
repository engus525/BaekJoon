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
typedef pair<ll, ll> pll;

int n;
queue<string> q[101];
string str;
vector<string> words;

void INPUT()
{
    IAMFAST
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        string sen; getline(cin, sen);
        string word;
        for(char s : sen)
        {
            if (s == ' ')
            {
                q[i].push(word);
                word = "";
            }
            else word += s;
        }
        q[i].push(word);
    }
    getline(cin, str);
}

void solution()
{
    //parsing
    string word;
    for(auto &s : str)
    {
        if (s == ' ')
        {
            words.emplace_back(word);
            word = "";
        }
        else word += s;
    }
    words.emplace_back(word);

    bool ans = true;
    for (int i = 0; i < words.size(); i++)
    {
        string now = words[i];

        bool possible = false;
        for(int j = 0; j < n; j++)
        {
            if (q[j].empty()) continue;
            if (q[j].front() == now)
            {
                q[j].pop();
                possible = true;
                break;
            }
        }

        if (!possible)
        {
            ans = false;
            break;
        }
    }

    //all queues must be empty
    bool allEmpty = true;
    for(int i = 0; i < n; i++)
        if (!q[i].empty()) allEmpty = false;

    if (allEmpty && ans) cout << "Possible";
    else cout << "Impossible";
}

int main()
{
    INPUT();
    solution();
}