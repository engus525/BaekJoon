#include <iostream>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;
vector<char> v(26);
bool visited[26];
int nPos = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> k;

}

void movePos(int cnt)
{
    nPos -= cnt;
    if (nPos < 0) nPos += n;
}

void Quit()
{
    cout << "!";
    exit(0);
}

void solution()
{
    for (int i = 0; i < n; i++) v[i] = 'x';

    while (k--)
    {
        int cnt;
        char c;
        cin >> cnt >> c;

        movePos(cnt % n);

        if (v[nPos] != 'x' && v[nPos] != c) Quit();
        if (v[nPos] != c && visited[c - 'A']) Quit();
        v[nPos] = c;
        visited[c - 'A'] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (v[(nPos + i) % n] == 'x') cout << "?";
        else cout << v[(nPos + i) % n];
    }

}

int main()
{
    INPUT();
    solution();
}