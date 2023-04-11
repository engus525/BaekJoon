#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int l,a,b,c,d;

void INPUT()
{
    IAMFAST
    cin >> l >> a >> b >> c >> d;
}

void SOLVE()
{
    int kor = a/c; if(a%c) kor++;
    int mat = b/d; if(b%d) mat++;
    cout << l-max(kor,mat);
}

int main()
{
    INPUT();
    SOLVE();
}