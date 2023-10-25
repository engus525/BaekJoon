#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int board[40], score[40], turn[40];
bool visited[40];
int piece[4] = {0,0,0,0};
int ans = 0;
vector<int> dice;

void INPUT()
{
    IAMFAST
    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;
        dice.emplace_back(num);
    }
}

void makeBoard()
{
    //0 -> 40
    for (int i = 0; i <= 20; i++) board[i] = i + 1;
    board[21] = 21;//도착

    //테두리 안쪽
    for (int i = 22; i <= 26; i++) board[i] = i + 1;
    board[27] = 20;
    for (int i = 30; i <= 31; i++) board[i] = i + 1;
    board[32] = 25;
    board[28] = 29, board[29] = 25;

    //파란색 화살표
    turn[5] = 22; turn[10] = 28; turn[15] = 30;


    //0 -> 40
    for (int i = 0; i <= 20; i++) score[i] = 2 * i;
    score[21] = 0;//도착

    //테두리 안쪽
    score[22] = 13, score[23] = 16, score[24] = 19;
    score[25] = 25, score[26] = 30, score[27] = 35;
    score[28] = 22, score[29] = 24;
    score[30] = 28, score[31] = 27, score[32] = 26;

}


void DFS(int depth, int point)
{
    if (depth == 10)
    {
        ans = max(ans, point);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int prev = piece[i];
        int now = prev;
        int cnt = dice[depth];

        if (turn[now])
        {
            now = turn[now];
            cnt--;
        }

        while (cnt--) now = board[now];
        if (now != 21 && visited[now]) continue;

        visited[prev] = false;
        visited[now] = true;
        piece[i] = now;

        DFS(depth + 1, point + score[now]);

        visited[prev] = true;
        visited[now] = false;
        piece[i] = prev;
    }
}

void solution()
{
    makeBoard();
    DFS(0, 0);
    cout << ans;
}

int main()
{
    INPUT();
    solution();
}