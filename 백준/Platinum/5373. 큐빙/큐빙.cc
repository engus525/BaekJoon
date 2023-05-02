#include <iostream>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define forx for(int x = 0; x < 3; x++)
#define fory for(int y = 0; y < 3; y++)

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
        forx fory cube[i][x][y] = color[i];
}

void U(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        forx temp[x] = cube[2][0][x];
        forx cube[2][0][2-x] = cube[5][x][0];
        forx cube[5][x][0] = cube[3][2][x];
        forx cube[3][2][x] = cube[4][2-x][2];
        forx cube[4][2-x][2] = temp[2-x];
    }
    else
    {
        forx temp[x] = cube[2][0][x];
        forx cube[2][0][2-x] = cube[4][2-x][2];
        forx cube[4][2-x][2] = cube[3][2][x];
        forx cube[3][2][x] = cube[5][x][0];
        forx cube[5][x][0] = temp[2-x];
    }
}
void D(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        forx temp[x] = cube[3][0][x];
        forx cube[3][0][2-x] = cube[5][2-x][2];
        forx cube[5][2-x][2] = cube[2][2][x];
        forx cube[2][2][x] = cube[4][x][0];
        forx cube[4][x][0] = temp[2-x];
    }
    else
    {
        forx temp[x] = cube[3][0][x];
        forx cube[3][0][2-x] = cube[4][x][0];
        forx cube[4][x][0] = cube[2][2][x];
        forx cube[2][2][x] = cube[5][2-x][2];
        forx cube[5][2-x][2] = temp[2-x];
    }
}
void F(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        forx temp[x] = cube[4][2][x];
        forx cube[4][2][x] = cube[1][0][2-x];
        forx cube[1][0][2-x] = cube[5][2][x];
        forx cube[5][2][x] = cube[0][2][x];
        forx cube[0][2][x] = temp[x];
    }
    else
    {
        forx temp[x] = cube[4][2][x];
        forx cube[4][2][x] = cube[0][2][x];
        forx cube[0][2][x] = cube[5][2][x];
        forx cube[5][2][x] = cube[1][0][2-x];
        forx cube[1][0][2-x] = temp[x];
    }
}
void B(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        forx temp[x] = cube[5][0][x];
        forx cube[5][0][2-x] = cube[1][2][x];
        forx cube[1][2][x] = cube[4][0][2-x];
        forx cube[4][0][2-x] = cube[0][0][2-x];
        forx cube[0][0][2-x] = temp[2-x];
    }
    else
    {
        forx temp[x] = cube[5][0][x];
        forx cube[5][0][2-x] = cube[0][0][2-x];
        forx cube[0][0][2-x] = cube[4][0][2-x];
        forx cube[4][0][2-x] = cube[1][2][x];
        forx cube[1][2][x] = temp[2-x];
    }
}
void L(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        forx temp[x] = cube[3][x][0];
        forx cube[3][x][0] = cube[1][x][0];
        forx cube[1][x][0] = cube[2][x][0];
        forx cube[2][x][0] = cube[0][x][0];
        forx cube[0][x][0] = temp[x];
    }
    else
    {
        forx temp[x] = cube[3][x][0];
        forx cube[3][x][0] = cube[0][x][0];
        forx cube[0][x][0] = cube[2][x][0];
        forx cube[2][x][0] = cube[1][x][0];
        forx cube[1][x][0] = temp[x];
    }
}
void R(char dir)
{
    int temp[3];
    if(dir == '+')
    {
        forx temp[x] = cube[2][x][2];
        forx cube[2][2-x][2] = *&cube[1][2-x][2];
        forx cube[1][2-x][2] = cube[3][2-x][2];
        forx cube[3][2-x][2] = cube[0][2-x][2];
        forx cube[0][2-x][2] = temp[2-x];
    }
    else
    {
        forx temp[x] = cube[2][x][2];
        forx cube[2][2-x][2] = cube[0][2-x][2];
        forx cube[0][2-x][2] = cube[3][2-x][2];
        forx cube[3][2-x][2] = cube[1][2-x][2];
        forx cube[1][2-x][2] = temp[2-x];
    }
}

void Turn(char pos, char dir)
{
    char temp[3][3];
    forx fory temp[x][y] = cube[pos][x][y];

    forx fory
        {
            if (dir=='+') cube[pos][y][2 - x] = temp[x][y];
            else cube[pos][2-y][x] = temp[x][y];
        }
}

void Ans()
{
    forx
    {
        fory cout << cube[0][x][y];
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