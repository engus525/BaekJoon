#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int t;
map<int, string> M;

void INPUT()
{
    IAMFAST
    cin >> t;
}

void solution()
{
    M.emplace(1, "Yakk");
    M.emplace(2, "Doh");
    M.emplace(3, "Seh");
    M.emplace(4, "Ghar");
    M.emplace(5, "Bang");
    M.emplace(6, "Sheesh");

    for (int i = 1; i <= t; i++)
    {
        int a, b; cin >> a >> b;
        if (a < b) swap(a, b);

        cout << "Case " << i << ": ";
        if (a == 6 && b == 5) cout << "Sheesh Beesh\n";
        else if (a == b)
        {
            if (a == 1) cout << "Habb Yakk\n";
            else if (a == 2) cout << "Dobara\n";
            else if (a == 3) cout << "Dousa\n";
            else if (a == 4) cout << "Dorgy\n";
            else if (a == 5) cout << "Dabash\n";
            else if (a == 6) cout << "Dosh\n";
        }
        else cout << M[a] << " " << M[b] << '\n';
    }
}

int main()
{
    INPUT();
    solution();
}