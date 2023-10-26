#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, A, B;
    cin >> a >> b;
    A = min(a,b);
    B = max(a,b);
    cout << (A+B)*(B-A+1)/2;
}