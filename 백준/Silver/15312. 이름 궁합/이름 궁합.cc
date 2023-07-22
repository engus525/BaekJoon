#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);

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

    cout << v[0] << v[1];
}

int main()
{
    INPUT();
    solution();
}