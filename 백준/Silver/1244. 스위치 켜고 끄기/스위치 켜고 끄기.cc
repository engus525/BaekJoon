#include <iostream>
using namespace std;

int n;
int button[101];
int k;

void INPUT()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> button[i];
    cin >> k;
}

void changeMultiple(int num)
{
    for(int i = 1; num * i <= n; i++)
        button[num * i] = 1 - button[num * i];
}

void changeSection(int num)
{
    for(int i = 0; 1 <= num - i && num + i <= n; i++)
    {
        if (i == 0) button[num] = 1 - button[num];
        else if(button[num - i] == button[num + i])
        {
            button[num - i] = 1 - button[num - i];
            button[num + i] = 1 - button[num + i];
        }
        else break;
    }
}

void SOLVE()
{
    while(k--)
    {
        int sex, num; cin >> sex >> num;

        // 남자
        if(sex == 1) changeMultiple(num);
        else changeSection(num);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << button[i] << " ";
        if(i % 20 == 0) cout << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}
