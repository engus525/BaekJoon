#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef pair<int, int> pii;

int n, q;
vector<pii> v;

void INPUT()
{
    IAMFAST
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        v.emplace_back(num, i+1);
    }
}


void solution()
{
    sort(v.begin(), v.end());

    while(q--)
    {

        int command, inp;
        cin >> command >> inp;

        if (command == 1)
        {
            int left = 0, right = n - 1;
            bool can = false;
            while(left < right)
            {
                int mul = v[left].first * v[right].first;
                if (mul == inp)
                {
                    can = true;
                    break;
                }
                else if (v[left].first == 0)  left++;
                else if (v[right].first == 0)  right--;
                else if (mul < inp) left++;
                else right--;
            }
            cout << can << '\n';
        }
        else
        {
            for(auto &i : v)
            {
                if (i.second == inp)
                    i.first = 0;
            }
        }
    }
}

int main()
{
    INPUT();
    solution();
}