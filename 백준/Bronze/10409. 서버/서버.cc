#include <iostream>

using namespace std;

int main() {

	int n, t;

	cin >> n >> t;



	int a,sum=0,cnt=0;	



	for (int i = 0; i < n; i++) {

		cin >> a;

		sum += a;

		if (sum <= t)

			cnt++;

	}

	cout << cnt;

}


