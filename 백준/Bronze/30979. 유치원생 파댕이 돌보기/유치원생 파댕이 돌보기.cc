#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, N;
    cin >> T >> N;
    
    vector<int> F(N);
    int sum = 0;
    
    for(int i = 0; i < N; ++i) {
        cin >> F[i];
        sum += F[i];
    }
    
    cout << (T <= sum ? "Padaeng_i Happy" : "Padaeng_i Cry") << '\n';
    
    return 0;
}
