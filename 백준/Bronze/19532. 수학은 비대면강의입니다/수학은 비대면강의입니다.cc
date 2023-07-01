#include <iostream>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

int a,b,c,d,e,f;

void INPUT()
{
    IAMFAST
    cin >> a >> b >> c >> d >> e >> f;
}

void SOLVE()
{
    for(int i = -999; i <= 999; i++)
        for(int j = -999; j <= 999; j++)
            if((a-d)*i + (b-e)*j == c-f)
                if(a*i + b*j == c)
                    if(d*i + e*j == f)
                    {
                        cout << i << " " << j;
                        return;
                    }
}

int main()
{
    INPUT();
    SOLVE();
}