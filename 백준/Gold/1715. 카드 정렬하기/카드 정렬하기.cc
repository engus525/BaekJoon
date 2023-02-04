#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> Q;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

cin >> N;
// 정렬된 묶음이 한개만 들어오면 비교할 필요 없다.
if (N == 1) {
	cout << 0 << '\n';
	return 0;
}

for (int i = 0; i < N; ++i) {
	int a;
	cin >> a;
	Q.push(a);
}
int ans = 0;
// 최대한 작은 애들을 먼저 묶는다.
while (Q.size() > 1) {
	int a = Q.top();
	Q.pop();
	int b = Q.top();
	Q.pop();
	ans += a + b;
	Q.push(a + b);
}
cout << ans << '\n';

return 0;
}