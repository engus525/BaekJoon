#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m;
char nuclear[4] = {'A','C','G','T'};
string dna[1001];
string ans = "";
int dist = 0;

void INPUT()
{
    IAMFAST
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> dna[i];
}

void setDNA(int cnt[30])
{
    char c;
    int Max = 0;
    for(int i = 0; i < 4; i++)
    {
        if(Max < cnt[nuclear[i]-'A'])
        {
            Max = cnt[nuclear[i]-'A'];
            c = nuclear[i];
        }
    }
    ans += c;
    dist += n-Max;
}

void SOLVE()
{
    for(int i = 0; i < m; i++)
    {
        int cnt[30] = {0};
        for(int j = 0; j < n ; j++)
            cnt[dna[j][i]-'A']++;

        setDNA(cnt);
    }
    cout << ans << "\n" << dist;
}

int main()
{
    INPUT();
    SOLVE();
}