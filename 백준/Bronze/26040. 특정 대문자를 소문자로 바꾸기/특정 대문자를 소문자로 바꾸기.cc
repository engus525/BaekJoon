#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

string str, target;
bool visited[27];

void INPUT()
{
    IAMFAST
    cin >> str;
    cin.ignore();
    getline(cin, target);
    for (auto &t : target)
        if (t != ' ') visited[t - 'A'] = true;
}


void solution()
{
    for (auto &s : str)
    {
        if ('A' <= s && s <= 'Z' && visited[s - 'A']) s -= 'A', s += 'a';
        cout << s;
    }
}

int main()
{
    INPUT();
    solution();
}