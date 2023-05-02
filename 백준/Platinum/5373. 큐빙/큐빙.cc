#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t,n;
string mov;
char cube[6][3][3];

void INPUT()
{
    IAMFAST
    cin >> t;
}

void Init()
{
    char color[6] = {'w','y','r','o','g','b'};
    for(int i = 0; i < 6; i++)
        for(int x = 0; x < 3; x++)
            for(int y = 0; y < 3; y++)
                cube[i][x][y] = color[i];
}

void U(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[2][0][i];
        for(int i = 0; i < 3; i++) cube[2][0][2-i] = cube[5][i][0];
        for(int i = 0; i < 3; i++) cube[5][i][0] = cube[3][2][i];
        for(int i = 0; i < 3; i++) cube[3][2][i] = cube[4][2-i][2];
        for(int i = 0; i < 3; i++) cube[4][2-i][2] = temp[2-i];
    }
    else
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[2][0][i];
        for(int i = 0; i < 3; i++) cube[2][0][2-i] = cube[4][2-i][2];
        for(int i = 0; i < 3; i++) cube[4][2-i][2] = cube[3][2][i];
        for(int i = 0; i < 3; i++) cube[3][2][i] = cube[5][i][0];
        for(int i = 0; i < 3; i++) cube[5][i][0] = temp[2-i];
    }
}
void D(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[3][0][i];
        for(int i = 0; i < 3; i++) cube[3][0][2-i] = cube[5][2-i][2];
        for(int i = 0; i < 3; i++) cube[5][2-i][2] = cube[2][2][i];
        for(int i = 0; i < 3; i++) cube[2][2][i] = cube[4][i][0];
        for(int i = 0; i < 3; i++) cube[4][i][0] = temp[2-i];
    }
    else
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[3][0][i];
        for(int i = 0; i < 3; i++) cube[3][0][2-i] = cube[4][i][0];
        for(int i = 0; i < 3; i++) cube[4][i][0] = cube[2][2][i];
        for(int i = 0; i < 3; i++) cube[2][2][i] = cube[5][2-i][2];
        for(int i = 0; i < 3; i++) cube[5][2-i][2] = temp[2-i];
    }
}
void F(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[4][2][i];
        for(int i = 0; i < 3; i++) cube[4][2][i] = cube[1][0][2-i];
        for(int i = 0; i < 3; i++) cube[1][0][2-i] = cube[5][2][i];
        for(int i = 0; i < 3; i++) cube[5][2][i] = cube[0][2][i];
        for(int i = 0; i < 3; i++) cube[0][2][i] = temp[i];
    }
    else
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[4][2][i];
        for(int i = 0; i < 3; i++) cube[4][2][i] = cube[0][2][i];
        for(int i = 0; i < 3; i++) cube[0][2][i] = cube[5][2][i];
        for(int i = 0; i < 3; i++) cube[5][2][i] = cube[1][0][2-i];
        for(int i = 0; i < 3; i++) cube[1][0][2-i] = temp[i];
    }
}
void B(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[5][0][i];
        for(int i = 0; i < 3; i++) cube[5][0][2-i] = cube[1][2][i];
        for(int i = 0; i < 3; i++) cube[1][2][i] = cube[4][0][2-i];
        for(int i = 0; i < 3; i++) cube[4][0][2-i] = cube[0][0][2-i];
        for(int i = 0; i < 3; i++) cube[0][0][2-i] = temp[2-i];
    }
    else
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[5][0][i];
        for(int i = 0; i < 3; i++) cube[5][0][2-i] = cube[0][0][2-i];
        for(int i = 0; i < 3; i++) cube[0][0][2-i] = cube[4][0][2-i];
        for(int i = 0; i < 3; i++) cube[4][0][2-i] = cube[1][2][i];
        for(int i = 0; i < 3; i++) cube[1][2][i] = temp[2-i];
    }
}
void L(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[3][i][0];
        for(int i = 0; i < 3; i++) cube[3][i][0] = cube[1][i][0];
        for(int i = 0; i < 3; i++) cube[1][i][0] = cube[2][i][0];
        for(int i = 0; i < 3; i++) cube[2][i][0] = cube[0][i][0];
        for(int i = 0; i < 3; i++) cube[0][i][0] = temp[i];
    }
    else
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[3][i][0];
        for(int i = 0; i < 3; i++) cube[3][i][0] = cube[0][i][0];
        for(int i = 0; i < 3; i++) cube[0][i][0] = cube[2][i][0];
        for(int i = 0; i < 3; i++) cube[2][i][0] = cube[1][i][0];
        for(int i = 0; i < 3; i++) cube[1][i][0] = temp[i];
    }
}
void R(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[2][i][2];
        for(int i = 0; i < 3; i++) cube[2][2-i][2] = cube[1][2-i][2];
        for(int i = 0; i < 3; i++) cube[1][2-i][2] = cube[3][2-i][2];
        for(int i = 0; i < 3; i++) cube[3][2-i][2] = cube[0][2-i][2];
        for(int i = 0; i < 3; i++) cube[0][2-i][2] = temp[2-i];
    }
    else
    {
        for(int i = 0; i < 3; i++) temp[i] = cube[2][i][2];
        for(int i = 0; i < 3; i++) cube[2][2-i][2] = cube[0][2-i][2];
        for(int i = 0; i < 3; i++) cube[0][2-i][2] = cube[3][2-i][2];
        for(int i = 0; i < 3; i++) cube[3][2-i][2] = cube[1][2-i][2];
        for(int i = 0; i < 3; i++) cube[1][2-i][2] = temp[2-i];
    }
}

void Turn(char pos, char dir)
{
    char temp[3][3];
    for(int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            temp[x][y] = cube[pos][x][y];

    if(dir == '+')
    {
        for(int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                cube[pos][y][2-x] = temp[x][y];
    }
    else
    {
        for(int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                cube[pos][2-y][x] = temp[x][y];
    }
}

void Ans()
{
    for(int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
            cout << cube[0][x][y];
        cout << '\n';
    }
}

void SOLVE()
{

    while(t--)
    {
        Init();

        cin >> n;
        while(n--)
        {
            cin >> mov;
            char dir = mov[1];

            if(mov[0]=='U') Turn(0,dir),U(dir);
            else if(mov[0]=='D') Turn(1,dir),D(dir);
            else if(mov[0]=='F') Turn(2,dir),F(dir);
            else if(mov[0]=='B') Turn(3,dir),B(dir);
            else if(mov[0]=='L') Turn(4,dir),L(dir);
            else if(mov[0]=='R') Turn(5,dir),R(dir);

        }
        Ans();
    }
}

int main()
{
    INPUT();
    SOLVE();
}