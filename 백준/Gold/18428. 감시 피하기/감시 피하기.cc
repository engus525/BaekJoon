#include <iostream>
#include <vector>
using namespace std;

int n;
char map[7][7];
vector<pair<int,int>> teacher;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 'T')
                teacher.push_back({i,j});
        }
}

bool Search()
{
    for(int i = 0; i < teacher.size(); i++)
    {
        int x = teacher[i].first;
        int y = teacher[i].second;

        //상
        for(int j = x - 1; j >= 0; j--)
        {
            if(map[j][y] == 'O') break;
            else if(map[j][y] == 'S') return true;
        }
        //하
        for(int j = x + 1; j < n; j++)
        {
            if(map[j][y] == 'O') break;
            else if(map[j][y] == 'S') return true;
        }
        //좌
        for(int j = y - 1; j >= 0; j--)
        {
            if(map[x][j] == 'O') break;
            else if(map[x][j] == 'S') return true;
        }
        //우
        for(int j = y + 1; j < n; j++)
        {
            if(map[x][j] == 'O') break;
            else if(map[x][j] == 'S') return true;
        }

    }

    return false;
}

void permutation(int cnt, pair<int,int> start)
{
    if(cnt == 3)
    {
        if(!Search())
        {
            cout << "YES";
            exit(0);
        }
        else return;
    }

    bool init = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(!init)
            {
                i = start.first;
                j = start.second;
                init = true;
            }

            if(map[i][j] == 'X')
            {
                map[i][j] = 'O';
                //cout << i << " " << j << " barrier\n";
                permutation(cnt + 1, {i,j});
                map[i][j] = 'X';
            }
        }
}

void SOLVE()
{
    permutation(0, {0,0});
    cout << "NO";
}

int main()
{
    INPUT();
    SOLVE();
}
