#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string s,t;

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> t;
}

void BFS()
{
    queue<string> q;
    q.push(t);

    while(!q.empty())
    {
        string now = q.front();
        q.pop();

        string next1,next2;

        // 뒤에 A 제거
        next1 = now;
        if(next1[next1.length()-1] == 'A')
        {
            next1.pop_back();
            if(next1 == s) { cout << 1; exit(0); }//종료 조건
            q.push(next1);
        }

        // 뒤집은 후 뒤에 B 제거
        next2 = now;
        if(next2[0] == 'B')
        {
            reverse(next2.begin(),next2.end());
            next2.pop_back();
        }
        else continue;

        if(next2 == s) { cout << 1; exit(0); }//종료 조건
        if(next1 == next2)continue;
        else q.push(next2);
    }
}


void SOLVE()
{
    BFS();
    cout << 0;
}

int main()
{
    INPUT();
    SOLVE();
}