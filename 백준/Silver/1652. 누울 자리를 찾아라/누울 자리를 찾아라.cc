#include <bits/stdc++.h>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
char graph[101][101];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
            graph[i][j] = str[j];
    }
}


void solution()
{
    int ansA = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == '.') cnt++;
            else cnt = 0;

            if (cnt == 2) ansA++;
        }
    }

    int ansB = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[j][i] == '.') cnt++;
            else cnt = 0;

            if (cnt == 2) ansB++;
        }
    }

    cout << ansA << " " << ansB;
}

int main()
{
    INPUT();
    solution();
}