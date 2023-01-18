#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int n;
int board[21][21], origin[21][21]; // 옮기는 보드, 원본
int permu[5];
bool gathered[21][21];

int ans = 0;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> origin[i][j];
}

int maxBlock()
{// 보드 내 가장 큰 블록 return
    int MAX = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            MAX = max(MAX, board[i][j]);
    return MAX;
}

void copyBoard()
{// BackTracking을 위해 board 복사
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = origin[i][j];
}

void UP()
{

    for(int i = 0; i < n; i++)
    {// n개의 열에 대하여 위 원소부터 하나씩 올린다.

        for(int j = 1; j < n; j++)
        {
            int process = j;

            if (board[j][i] != 0)
            {
                while (true)
                {
                    if (!gathered[process - 1][i]
                    && board[process][i] == board[process - 1][i])
                    {// 합쳐진다면
                        board[process - 1][i] += board[process][i];
                        board[process][i] = 0;
                        gathered[process - 1][i] = true;
                        break;
                    }
                    else if (board[process - 1][i] == 0 && 0 < process)
                    {// 옮길 수 있다면
                        board[process - 1][i] = board[process][i];
                        board[process][i] = 0;
                        process--;
                    }
                    else break;
                }
            }
        }// for j end
    }
}

void DOWN()
{
    for(int i = 0; i < n; i++)
    {// n개의 열에 대하여 아래 원소부터 하나씩 내린다.

        for(int j = n - 2; j >= 0; j--)
        {
            int process = j;

            if (board[j][i] != 0)
            {
                while (true)
                {
                    if (!gathered[process + 1][i]
                    && board[process][i] == board[process + 1][i])
                    {// 합쳐진다면
                        board[process + 1][i] += board[process][i];
                        board[process][i] = 0;
                        gathered[process + 1][i] = true;
                        break;
                    }
                    else if (board[process + 1][i] == 0 && process < n - 1)
                    {// 옮길 수 있다면
                        board[process + 1][i] = board[process][i];
                        board[process][i] = 0;
                        process++;
                    }
                    else break;
                }
            }
        }// for j end
    }

}

void LEFT()
{
    for(int i = 0; i < n; i++)
    {// n개의 행에 대하여 왼쪽 원소부터 하나씩 왼쪽으로 민다.

        for(int j = 1; j < n; j++)
        {
            int process = j;

            if (board[i][j] != 0)
            {
                while (true)
                {
                    if (!gathered[i][process - 1]
                    && board[i][process - 1] == board[i][process])
                    {// 합쳐진다면
                        board[i][process - 1] += board[i][process];
                        board[i][process] = 0;
                        gathered[i][process - 1] = true;
                        break;
                    }
                    else if (board[i][process - 1] == 0 && 0 < process)
                    {// 옮길 수 있다면
                        board[i][process - 1] = board[i][process];
                        board[i][process] = 0;
                        process--;
                    }
                    else break;
                }
            }
        }// for j end
    }

}

void RIGHT()
{

    for(int i = 0; i < n; i++)
    {// n개의 행에 대하여 왼쪽 원소부터 하나씩 오른쪽으로 민다.

        for(int j = n - 2; j >= 0; j--)
        {
            int process = j;

            if (board[i][j] != 0)
            {
                while (true)
                {
                    if (!gathered[i][process + 1]
                    && board[i][process + 1] == board[i][process])
                    {// 합쳐진다면
                        board[i][process + 1] += board[i][process];
                        board[i][process] = 0;
                        gathered[i][process + 1] = true;
                        break;
                    }
                    else if (board[i][process + 1] == 0 && process < n - 1)
                    {// 옮길 수 있다면
                        board[i][process + 1] = board[i][process];
                        board[i][process] = 0;
                        process++;
                    }
                    else break;
                }
            }
        }// for j end
    }
}

void move()
{
    for(int i = 0; i < 5; i++)
    {
        int dir = permu[i];

        for(int k = 0; k < n; k++)
            for(int j = 0; j < n; j++)
                gathered[k][j] = false;
        if(dir == 0) UP();
        else if(dir == 1) DOWN();
        else if(dir == 2) LEFT();
        else RIGHT();
    }

    ans = max(ans, maxBlock());
}

void setPermu(int cnt)
{
    if(cnt == 5)
    {
        copyBoard();
        move();
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        permu[cnt] = i;
        setPermu(cnt + 1);
    }
}
void SOLVE()
{
    setPermu(0);
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
