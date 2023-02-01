#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;

typedef long long ll;
vector<ll> num;
deque<char> oper;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
}

bool isOperand(char c)
{
    return c=='*'||c=='/'||c=='+'||c=='-';
}

bool oper1(char c)
{//mult or div
    return c=='*'||c=='/';
}
bool oper2(char c)
{//plus or minus
    return c=='+'||c=='-';
}

void Parsing()
{//수와 연산자 분리

    string token = "";
    for(int i = 0; i < str.length(); i++)
    {
        //연산자라면
        if(i && isOperand(str[i]))
            num.push_back(stoll(token)),
            token = "",
            oper.push_back(str[i]);
        //수라면
        else token += str[i];
    }num.push_back(stoll(token));
}

ll calc(ll a, ll b, char c)
{
    switch(c)
    {
        case '*' : return a*b;
        case '/' : return a/b;
        case '+' : return a+b;
        case '-' : return a-b;
    }
}

void SOLVE()
{
    Parsing();

    //연산자가 없는 경우
    if(oper.empty()) cout << num[0];

    ll left = 0 , right = num.size()-1;
    while(!oper.empty())
    {
        //마지막 연산
        if(oper.size() == 1)
        {
            ll ans = calc(num[left],num[left+1],oper.front());
            cout << ans;
            return;
        }

        //왼쪽의 우선순위가 높은 경우
        if(oper1(oper.front()) && oper2(oper.back()))
        {
            num[left+1] = calc(num[left],num[left+1],oper.front());
            left++;
            oper.pop_front();
        }
        //오른쪽의 우선순위가 높은 경우
        else if(oper2(oper.front()) && oper1(oper.back()))
        {
            num[right-1] = calc(num[right-1],num[right],oper.back());
            right--;
            oper.pop_back();
        }
        //우선순위 같은 경우
        else
        {
            ll tempL = calc(num[left],num[left+1],oper.front());
            ll tempR = calc(num[right-1],num[right],oper.back());

            //앞의 연산값이 크거나 같은 경우 앞에 먼저
            if(tempL >= tempR)
                num[left+1] = tempL , left++ , oper.pop_front();
            else num[right-1] = tempR , right-- , oper.pop_back();
        }
    }
}

int main()
{
    INPUT();
    SOLVE();
}