#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

#define START 123
#define END 987
int n, ask, s, b;
bool nums[1001]; // 123 ~ 987

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(nums, true, sizeof(nums));
}

bool isDuplication(int num)
{
    if(to_string(num)[0] == to_string(num)[1]
    || to_string(num)[0] == to_string(num)[2]
    || to_string(num)[1] == to_string(num)[2])
        return true;
    else return false;
}
bool strike(int num, int idx)
{
    if(to_string(ask)[idx] == to_string(num)[idx]) return true;
    else return false;
}

bool ball(int num, int idx)
{
    if(to_string(ask)[idx] == to_string(num)[(idx + 1) % 3]
    || to_string(ask)[idx] == to_string(num)[(idx + 2) % 3])
    {
        return true;
    }
    else return false;
}


void SOLVE()
{

    while(n--)
    {
        cin >> ask >> s >> b;

        for(int i = START; i <= END; i++)
        {

            if(isDuplication(i)) nums[i] = false;
            if(to_string(i)[0] == '0'
            || to_string(i)[1] == '0'
            || to_string(i)[2] == '0')
                nums[i] = false;

            // Strike process
            if(s == 3)
            {
                if(!(strike(i,0)&&strike(i,1)&&strike(i,2)))
                    nums[i] = false;
            }
            else if(s == 2)
            {
                if(!((!strike(i,0) && strike(i,1) && strike(i,2))
                || (strike(i,0) && !strike(i,1) && strike(i,2))
                || (strike(i,0) && strike(i,1) && !strike(i,2))))
                {
                    nums[i] = false;
                }
            }
            else if(s == 1)
            {
                if(!((strike(i,0) && !strike(i,1) && !strike(i,2))
                || (!strike(i,0) && strike(i,1) && !strike(i,2))
                || (!strike(i,0) && !strike(i,1) && strike(i,2))))
                {
                    nums[i] = false;
                }
            }
            else if(s == 0)
            {
                if(strike(i,0) || strike(i,1) || strike(i,2))
                {
                    nums[i] = false;
                }
            }
            // Strike process ends

            // Ball process
            if (b == 3)
            {
                if(!(ball(i,0) && ball(i,1) && ball(i,2)))
                {
                    nums[i] = false;
                }
            }
            else if(b==2)
            {
                if(!((!ball(i,0) && ball(i,1) && ball(i,2))
                || (ball(i,0) && !ball(i,1) && ball(i,2))
                || (ball(i,0) && ball(i,1) && !ball(i,2))))
                {
                    nums[i] = false;
                }
            }
            else if(b==1)
            {
                if(!((ball(i,0) && !ball(i,1) && !ball(i,2))
                || (!ball(i,0) && ball(i,1) && !ball(i,2))
                || (!ball(i,0) && !ball(i,1) && ball(i,2))))
                {
                    nums[i] = false;
                }
            }
            else if(b == 0)
            {
                if(ball(i,0) || ball(i,1) || ball(i,2))
                {
                    nums[i] = false;
                }
            }
            // Ball process ends
        }

    }

    int ans = 0;
    for(int i = START; i <= END; i++)
    {
        if(nums[i]) ans++;
    }
    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}
