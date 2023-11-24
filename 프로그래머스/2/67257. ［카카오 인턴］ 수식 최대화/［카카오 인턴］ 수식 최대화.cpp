#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;
typedef long long ll;

vector<char> operand;
vector<ll> num;
char R[6][3] = {{'+','-','*'},
                   {'+','*','-'},
                   {'-','+','*'},
                   {'-','*','+'},
                   {'*','+','-'},
                   {'*','-','+'}};

void Seperate(string str)
{
    string n;
    for (auto &s : str)
    {
        if ('0' <= s && s <= '9') n += s;
        else operand.push_back(s), num.push_back(stoi(n)), n = "";
    }
    num.push_back(stoi(n));
}

ll calc(char c, ll a, ll b)
{
    cout << c << " with " << a << " and " << b << '\n';
    if (c == '-') return a - b;
    else if (c == '+') return a + b;
    else return a * b;
}

ll calOnRank(int r)
{
    ll result = 0;
    
    auto oper = operand;
    auto n = num;
    for (int i = 0; i < 3; i++)
    {
        
        char op = R[r][i];
        ll temp = 0;
        for (int j = 0; j < oper.size(); j++)
        {
            if (oper[j] == op)
            {
                n[j] = calc(op, n[j], n[j + 1]);
                cout << "j = " << j << '\n';
                cout << "calc = " << n[j] << '\n';
                n.erase(n.begin() + j + 1);
                oper.erase(oper.begin() + j);
                j--;
            }
        }
        
        
    }
    result = max(result, abs(n[0]));
    cout << result << '\n';
    return result;
}

ll solution(string expression) {
    ll answer = 0;
    
    Seperate(expression);
    
    for (auto i : operand) cout << i << " ";
    cout << '\n';
    for (auto i : num) cout << i << " ";
    cout << '\n';
    
    for (int i = 0; i < 6; i++)
    {
        answer = max(answer, calOnRank(i));
        cout << "\n=========\n";
    }
    
    return answer;
}