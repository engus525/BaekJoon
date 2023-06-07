#include <iostream>
#include <stack>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
stack<int> stick;

void INPUT()
{
    IAMFAST
    cin >> n;
}


void SOLVE()
{
    for(int i = 0; i < n; i++)
    {
        int len; cin >> len;
        if(stick.empty()) stick.push(len);
        else if(len >= stick.top())
        {
            while(!stick.empty() && len >= stick.top())
                stick.pop();
            stick.push(len);
        }
        else stick.push(len);
    }

    cout << stick.size();
}

int main()
{
    INPUT();
    SOLVE();
}