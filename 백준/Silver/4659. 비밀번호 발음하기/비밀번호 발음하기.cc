#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str;

bool aeiou = false;
int check[2];//연속된 모음 갯수,연속된 자음 갯수
int cnt = 1;
char last;
void INPUT()
{
    IAMFAST
}


bool isAEIOU(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}


void Init()
{
    aeiou = false;
    memset(check,0,sizeof check);
    if(isAEIOU(str[0]))
        check[0] = 1 , aeiou = true;
    else check[1] = 1;
    cnt = 1;
    last = str[0];
}


void SOLVE()
{
    while(cin >> str)
    {
        if(str == "end") break;

        Init();


        string ans = "is acceptable.";

        for(int i = 1; i < str.length(); i++)
        {

            if(isAEIOU(str[i]))
                aeiou = true , check[0]++ , check[1] = 0;
            else check[1]++ , check[0] = 0;


            if(str[i] == last) cnt++;
            else cnt = 1;

            last = str[i];

            //모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
            if(check[0] == 3 || check[1] == 3)
            {
                ans = "is not acceptable.";
                break;
            }
            //같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
            else if(cnt == 2 && !(str[i] == 'e' || str[i] == 'o'))
            {
                ans = "is not acceptable.";
                break;
            }
        }//for end

        if(!aeiou) ans = "is not acceptable.";

        cout << "<"<<str<<"> " << ans << '\n';
    }
}

int main()
{
    INPUT();
    SOLVE();
}