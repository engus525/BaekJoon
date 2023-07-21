#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

string A, B;
int cnt[26] = {3, 2, 1, 2, 3, 3, 2, 3,
               3, 2, 2, 1, 2, 2, 1, 2,
               2, 2, 1, 2, 1, 1, 1, 2,
               2, 1};

void INPUT()
{
    IAMFAST
    cin >> A >> B;
}


void solution()
{
    vector<int> v;
    for(int i = 0 ; i < A.length(); i++)
        v.emplace_back(cnt[A[i]-'A']),
        v.emplace_back(cnt[B[i]-'A']);

    while(v.size() > 2)
    {
        vector<int> temp;
        for(int i = 0; i < v.size()-1; i++)
            temp.emplace_back((v[i]+v[i+1])%10);
        v = temp;
    }

    if(v.size() == 1) cout << 0 << v[0];
    else cout << v[0] << v[1];
}

int main()
{
    INPUT();
    solution();
}