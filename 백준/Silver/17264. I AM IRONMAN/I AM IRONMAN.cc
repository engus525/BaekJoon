#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, p;
int w, l, g;
unordered_map<string, char> M;
string name;
char wl;

void INPUT()
{
    IAMFAST
    cin >> n >> p >> w >> l >> g;
    for (int i = 0; i < p; i++)
    {
        cin >> name >> wl;
        M.emplace(name,wl);
    }

}


void solution()
{
    int score = 0;
    while (n--)
    {
        cin >> name;

        if (M[name] == 'W') score += w;
        else score = max(0, score - l);

        if (score >= g)
        {
            cout << "I AM NOT IRONMAN!!";
            return;
        }
    }
    cout << "I AM IRONMAN!!";
}

int main()
{
    INPUT();
    solution();
}