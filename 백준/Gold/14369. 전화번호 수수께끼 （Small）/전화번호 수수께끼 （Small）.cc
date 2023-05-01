#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t;
string str;
int cnt[27];
vector<int> ans;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void firstUnique()
{
    //0,2,4,6,8은 각각 z,w,u,x,g로 유니크함
    while (cnt['Z' - 'A'])
        ans.push_back(0),
                cnt['Z' - 'A']--, cnt['E' - 'A']--, cnt['R' - 'A']--, cnt['O' - 'A']--;

    while (cnt['W' - 'A'])
        ans.push_back(2),
                cnt['T' - 'A']--, cnt['W' - 'A']--, cnt['O' - 'A']--;

    while (cnt['U' - 'A'])
        ans.push_back(4),
                cnt['F' - 'A']--, cnt['O' - 'A']--, cnt['U' - 'A']--, cnt['R' - 'A']--;

    while (cnt['X' - 'A'])
        ans.push_back(6),
                cnt['S' - 'A']--, cnt['I' - 'A']--, cnt['X' - 'A']--;

    while (cnt['G' - 'A'])
        ans.push_back(8),
                cnt['E' - 'A']--, cnt['I' - 'A']--, cnt['G' - 'A']--, cnt['H' - 'A']--, cnt['T' - 'A']--;
}

void secondUnique()
{
    //4가 없다면, 3,5,7은 각각 r,f,v로 유일
    while (cnt['R' - 'A'])
        ans.push_back(3),
                cnt['T' - 'A']--, cnt['H' - 'A']--, cnt['R' - 'A']--, cnt['E' - 'A']--, cnt['E' - 'A']--;

    while (cnt['F' - 'A'])
        ans.push_back(5),
                cnt['F' - 'A']--, cnt['I' - 'A']--, cnt['V' - 'A']--, cnt['E' - 'A']--;

    while (cnt['V' - 'A'])
        ans.push_back(7),
                cnt['S' - 'A']--, cnt['E' - 'A']--, cnt['V' - 'A']--, cnt['E' - 'A']--, cnt['N' - 'A']--;

}

void lastUnique()
{
    //2~8이 없다면, 1은 O로 유일
    while (cnt['O' - 'A'])
        ans.push_back(1),
                cnt['O' - 'A']--, cnt['N' - 'A']--, cnt['E' - 'A']--;
}

void nine()
{
    //0~8 모두 소거
    while (cnt['N' - 'A'])
        ans.push_back(9),
                cnt['N' - 'A']--, cnt['I' - 'A']--, cnt['N' - 'A']--, cnt['E' - 'A']--;
}

void SOLVE()
{
    //Init


    int Case = 1;
    while (t--)
    {
        cin >> str;
        for (auto i: str) cnt[i - 'A']++;
        ans.clear();

        firstUnique();
        secondUnique();
        lastUnique();
        nine();

        sort(ans.begin(), ans.end());

        cout << "Case #" << Case++ << ": ";
        for (auto i: ans) cout << i;
        cout << '\n';
    }

}

int main()
{
    INPUT();
    SOLVE();
}