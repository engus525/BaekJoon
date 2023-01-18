#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int sudoku[9][9];
vector<pii> zero;

void INPUT()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            scanf("%1d", &sudoku[i][j]);
            if (!sudoku[i][j]) zero.push_back({i, j});
        }
}

bool checkHorizontal(int row, int n)
{
    for (int i = 0; i < 9; i++)
        if (sudoku[row][i] == n) return false;
    return true;
}

bool checkVertical(int col, int n)
{
    for (int i = 0; i < 9; i++)
        if (sudoku[i][col] == n) return false;
    return true;
}

bool checkArea(int x, int y, int n)
{
    int startX = (x / 3) * 3, startY = (y / 3) * 3;
    for (int i = startX; i < startX + 3; i++)
        for (int j = startY; j < startY + 3; j++)
            if (sudoku[i][j] == n)
                return false;
    return true;
}

void SOLVE()
{
    /*
     * 앞에서부터 작은 수를 채우되,
     * 들어갈 수 있는 수가 없는 칸을 만나면 이전 칸으로 돌아와 다시 채우기를 반복
     */
    int vSize = zero.size();
    for (int i = 0; i < vSize; i++)
    {
        
        int x = zero[i].first, y = zero[i].second;
        // If Empty position

        // find the min num that can fill the position
        bool filled = false;
        for (int num = sudoku[x][y] + 1; num <= 9; num++)
        {
            // Check three condition
            if (checkHorizontal(x, num)
                && checkVertical(y, num)
                && checkArea(x, y, num))
            {
                sudoku[x][y] = num;
                filled = true;
                break;
            }
        }

        // No num to fill in, back to previous position
        if (!filled)
        {
            sudoku[x][y] = 0;
            i -= 2;
            //if(i == 0) i--;
            //else i -= 2;
        }

    }//for i end

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j];
        cout << "\n";
    }
}

int main()
{
    INPUT();
    SOLVE();
}
