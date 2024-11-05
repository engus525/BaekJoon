#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define MOD 10007

int a[100001], b[100001];


int solution(int n, vector<int> tops) {
    
    a[0] = 1, b[0] = 0;
    for (int i = 1; i <= tops.size(); i++)
    {
        if (tops[i - 1]) a[i] = 3 * a[i - 1] + 2 * b[i - 1], b[i] = a[i - 1] + b[i - 1];
        else a[i] = 2 * a[i - 1] + b[i - 1], b[i] = a[i - 1] + b[i - 1];
        
        a[i] %= MOD, b[i] %= MOD;
        // cout << i << " : " << (a[i] + b[i]) % MOD << '\n';
    }
    
    return (a[n] + b[n]) % MOD;
}