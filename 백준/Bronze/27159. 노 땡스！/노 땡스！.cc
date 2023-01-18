#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> Get;
bool card[36];

void INPUT()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        Get.push_back(num);
        card[num] = true;
    }
}


void SOLVE()
{
    int ans = 0;

    for(int i = 0; i < Get.size(); i++)
    {
        if(!card[Get[i] - 1]) ans += Get[i];
    }

    cout << ans;
}

int main()
{
    INPUT();
    SOLVE();
}