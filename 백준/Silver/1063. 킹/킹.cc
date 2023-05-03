#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string k,s;
int n;
string mov;
int map[9][9];
char colPos[8] = {'A','B','C','D','E','F','G','H'};
typedef pair<int,int> pii;
pii king,stone;

void INPUT()
{
    IAMFAST
    cin >> k >> s >> n;
}

pii getPos(string str)
{
    pii rtn;
    for(int i = 1; i <= 8; i++)
        if(str[1] == i+'0')
            rtn.first = 8-i;
    for(int i = 0; i < 8; i++)
        if(str[0] == colPos[i])
            rtn.second = i;
    return rtn;
}

void Move(string str)
{
    pii step;
    if (str=="R") step = {0,1};
    else if (str=="L") step = {0,-1};
    else if (str=="B") step = {1,0};
    else if (str=="T") step = {-1,0};
    else if (str=="RT") step = {-1,1};
    else if (str=="LT") step = {-1,-1};
    else if (str=="RB") step = {1,1};
    else if (str=="LB") step = {1,-1};

    //킹이 이동할 위치 범위
    if(king.first+step.first < 0 || 7 < king.first+step.first ||
            king.second+step.second < 0 || 7 < king.second+step.second)
        return;

    if(map[king.first+step.first][king.second+step.second] == 2)
    {
        if (stone.first + step.first < 0 || 7 < stone.first + step.first ||
            stone.second + step.second < 0 || 7 < stone.second + step.second)
            return;

        stone.first += step.first;
        stone.second += step.second;
        map[stone.first][stone.second] = 2;
    }

    map[king.first][king.second] = 0;
    king.first += step.first;
    king.second += step.second;
    map[king.first][king.second] = 1;
}

void SOLVE()
{
    //init
    king = getPos(k);
    stone = getPos(s);
    map[king.first][king.second] = 1;
    map[stone.first][stone.second] = 2;

    while(n--)
    {
        cin >> mov;
        Move(mov);
    }

    cout << colPos[king.second] << 8-king.first << '\n';
    cout << colPos[stone.second] << 8-stone.first;

}

int main()
{
    INPUT();
    SOLVE();
}