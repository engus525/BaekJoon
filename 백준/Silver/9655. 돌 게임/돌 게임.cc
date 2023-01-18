#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;

	if (n % 2 == 0)
		cout << "CY";
	else cout << "SK";
}
