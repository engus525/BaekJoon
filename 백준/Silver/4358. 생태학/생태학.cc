#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

string tree;
int total = 0;
map<string, int> treeMap;

void INPUT()
{
    IAMFAST
}


void solution()
{
    while (getline(cin, tree))
    {
//        if (tree == "end") break;
        total++;
        treeMap[tree]++;
    }


    cout << fixed; cout.precision(4);
    for (auto elem : treeMap)
    {
        double val = (elem.second * 100 / (double) total);
        cout << elem.first << " " << val << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}