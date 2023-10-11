#include <iostream>
#include <algorithm>

using namespace std;
#define IAMFAST ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int list[500001];

void INPUT()
{
    IAMFAST
    cin >> n;
    for (int i = 0; i < n; i++) cin >> list[i];
    
}

void solution()
{
    sort(list, list + n);
    for (int i = 0; i < n; i++) cout << list[i] << " ";

}

int main()
{
    INPUT();
    solution();
}