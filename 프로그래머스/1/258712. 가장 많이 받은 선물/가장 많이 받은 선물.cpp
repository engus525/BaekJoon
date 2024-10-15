#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
typedef pair<string,string> pss;

map<pss, int> m;
vector<string> friends, gifts;
map<string, int> ansCnt;

pss parsingInput(string str)
{
    pss rtn;
    
    string name = "";
    for (auto s : str)
    {
        if (s == ' ') rtn.first = name, name = "";
        else name += s;
    }
    rtn.second = name;
    return rtn;
}

void calc(string a, string b)
{
    // cout << a << " " << b << " calc\n";
    int A = 0;
    for (auto name : friends) A += m[{a,name}], A -= m[{name,a}];
    int B = 0;
    for (auto name : friends) B += m[{b,name}], B -= m[{name,b}];
    
    // cout << "A : " << A << " , B : " << B << '\n';
    if (A > B) ansCnt[a]++;
    else if (A < B) ansCnt[b]++;
}

int solution(vector<string> f, vector<string> g) {
    friends = f, gifts = g;
    
    for (auto history : g)
    {
        auto in = parsingInput(history);
        m[{in.first,in.second}]++;
    }
    
    for (int i = 0; i < f.size(); i++)
    {
        for (int j = i + 1; j < f.size(); j++)
        {
            if (m[{f[i],f[j]}] < m[{f[j],f[i]}]) {ansCnt[f[j]]++;}
            else if (m[{f[i],f[j]}] > m[{f[j],f[i]}]) {ansCnt[f[i]]++;}
            else {calc(f[i], f[j]);}
        }
        // cout << f[i] << "'s ansCnt ========= : " << ansCnt[f[i]] << "\n";
    }
    
    int answer = 0;
    for (int i = 0; i < f.size(); i++)
    {
        // cout << ansCnt[f[i]] << " ";
        answer = max(answer, ansCnt[f[i]]);
    }
    
    return answer;
}