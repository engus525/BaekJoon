#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int n;
string control;
pair<int,int> dir[4] = {{-1,0},
                        {0,1},
                        {1,0},
                        {0,-1}};

void INPUT()
{
    IAMFAST
    cin >> n;
}

void SOLVE()
{
    while(n--)
    {
        int x = 0, y = 0, d = 0;
        int minX = 0, maxX = 0, minY = 0, maxY = 0;

        cin >> control;

        for(auto &c : control)
        {
            if (c == 'F') x += dir[d].first, y += dir[d].second;
            else if (c == 'B') x -= dir[d].first, y -= dir[d].second;
            else if (c == 'R') d = (d + 1) % 4;
            else if (c == 'L') d = (d - 1 == -1) ? 3 : d - 1;

            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }

        cout << (maxX - minX) * (maxY - minY) << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}