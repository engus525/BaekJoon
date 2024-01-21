#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int ans = 0;
    while (cin >> n) {
        ans += n;
    }
    cout << ans;
}