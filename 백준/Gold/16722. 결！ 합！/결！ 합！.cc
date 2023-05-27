#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct CARD
{
    int S;
    int C;
    int B;
};
CARD card[10];
bool sameCard[10][10][10];
bool visited[10][10][10];
int n;


void INPUT()
{
    IAMFAST
    for (int i = 1; i <= 9; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        CARD inp;
        if (a == "CIRCLE") inp.S = 0;
        else if (a == "TRIANGLE") inp.S = 1;
        else inp.S = 2;

        if (b == "YELLOW") inp.C = 0;
        else if (b == "RED") inp.C = 1;
        else inp.C = 2;

        if (c == "GRAY") inp.B = 0;
        else if (c == "WHITE") inp.B = 1;
        else inp.B = 2;
        card[i] = inp;
    }
    cin >> n;
}

int SH(CARD a, CARD b, CARD c)
{
    if(a.S == b.S && b.S == c.S) return 0;
    if(a.S != b.S && b.S != c.S && c.S != a.S) return 1;
    return 2;
}
int CH(CARD a, CARD b, CARD c)
{
    if(a.C == b.C && b.C == c.C) return 0;
    if(a.C != b.C && b.C != c.C && c.C != a.C) return 1;
    return 2;
}
int BH(CARD a, CARD b, CARD c)
{
    if(a.B == b.B && b.B == c.B) return 0;
    if(a.B != b.B && b.B != c.B && c.B != a.B) return 1;
    return 2;
}

bool isSame(CARD a, CARD b, CARD c)
{
    if(SH(a,b,c)==0 && CH(a,b,c)==0 && BH(a,b,c)==0) return true;

    if(SH(a,b,c)==1 && CH(a,b,c)==0 && BH(a,b,c)==0) return true;
    if(SH(a,b,c)==0 && CH(a,b,c)==1 && BH(a,b,c)==0) return true;
    if(SH(a,b,c)==0 && CH(a,b,c)==0 && BH(a,b,c)==1) return true;

    if(SH(a,b,c)==1 && CH(a,b,c)==1 && BH(a,b,c)==0) return true;
    if(SH(a,b,c)==1 && CH(a,b,c)==0 && BH(a,b,c)==1) return true;
    if(SH(a,b,c)==0 && CH(a,b,c)==1 && BH(a,b,c)==1) return true;

    if(SH(a,b,c)==1 && CH(a,b,c)==1 && BH(a,b,c)==1) return true;

    return false;
}

int countH()
{
    int cnt = 0;
    for (int i = 1; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            for (int k = j + 1; k < 10; k++)
            {
                if (isSame(card[i], card[j], card[k]))
                    sameCard[i][j][k] = true, cnt++;
            }
        }
    }
    return cnt;
}

void SOLVE()
{
    int cntH = countH();

    int ans = 0;
    bool hadG = false;
    while (n--)
    {
        string say; cin >> say;

        if(say == "H")
        {
            int select[3];
            for(int i = 0; i < 3; i++) cin >> select[i];
            sort(select,select+3);
            auto [a,b,c] = select;

            if(sameCard[a][b][c])
            {
                if(visited[a][b][c]) ans--;
                else visited[a][b][c] = true, ans++, cntH--;
            }
            else ans--;
        }
        else
        {
            if(!cntH && !hadG) ans += 3, hadG = true;
            else ans--;
        }
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}