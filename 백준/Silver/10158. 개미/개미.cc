#include <iostream>
#include <cmath>
using namespace std;

int w, h, p, q, t;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> w >> h >> p >> q >> t;
	
	p += t; q += t;
	p %= 2 * w; q %= 2 * h;
	if (p > w)
		p = 2 * w - p;
	if (q > h)
		q = 2 * h - q;

	cout << p << " " << q;
}