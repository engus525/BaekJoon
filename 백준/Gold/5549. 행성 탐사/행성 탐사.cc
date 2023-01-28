#include <iostream>
using namespace std;

int n,m;
char map[1001][1001];
int k;
int a,b,c,d;

int prefixSum[3][1001][1001];// J O I

void INPUT()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf("%1s",&map[i][j]);

            //누적합
            for(int area = 0; area < 3; area++)
            {
                prefixSum[area][i][j] =
                        prefixSum[area][i-1][j] + prefixSum[area][i][j-1] - prefixSum[area][i-1][j-1];
                if(area == 0 && map[i][j] == 'J') prefixSum[area][i][j]++;
                else if(area == 1 && map[i][j] == 'O') prefixSum[area][i][j]++;
                else if(area == 2 && map[i][j] == 'I') prefixSum[area][i][j]++;
            }
        }
}


void SOLVE()
{

    while(k--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);

        for(int area = 0; area < 3; area++)
        {
            printf("%d ", prefixSum[area][c][d]
                    - prefixSum[area][c][b-1]
                    - prefixSum[area][a-1][d]
                    + prefixSum[area][a-1][b-1]);
        }
        printf("\n");
    }

}

int main()
{
    INPUT();
    SOLVE();
}