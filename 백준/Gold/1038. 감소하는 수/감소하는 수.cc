#include <iostream>
#include <string>
using namespace std;

int n;
bool visited[10];
string descendingNum = "";

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
}

void permutation(int cnt, int limit)
{
    if(cnt == limit)
    {
        n--;
        if(n == -1)
        {
            cout << descendingNum;
            exit(0);
        }
        else return;
    }

    int last = (descendingNum.length()) ? descendingNum.back() - '0' : 10;
    for(int i = 0; i < last; i++)
    {
        descendingNum += i + '0';
        permutation(cnt + 1, limit);
        descendingNum.pop_back();
    }
}

void SOLVE()
{
    int len = 1;
    // 9876543210(len == 10) is Max
    while(len <= 10)
    {
        permutation(0, len);
        len++;
    }
    cout << -1;
}

int main()
{
    INPUT();
    SOLVE();
}
