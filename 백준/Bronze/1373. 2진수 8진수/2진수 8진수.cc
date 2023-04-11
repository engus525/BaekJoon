#include <iostream>
#include <stack>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str;
stack<int> st;

void INPUT()
{
    IAMFAST
    cin >> str;
}

void SOLVE()
{
    for(int i = str.length()-1; i >= 0; i-=3)
    {
        int tok = 0;
        if(i-2>=0) tok += 4*(str[i-2]-'0');
        if(i-1>=0) tok += 2*(str[i-1]-'0');
        if(i>=0) tok += 1*(str[i]-'0');
        st.push(tok);
    }
    while(!st.empty()) cout<<st.top(),st.pop();
}

int main()
{
    INPUT();
    SOLVE();
}