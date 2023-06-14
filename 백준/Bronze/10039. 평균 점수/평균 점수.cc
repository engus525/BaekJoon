#include <iostream>

using namespace std;

int main() {
	int score, total = 0;
	for (int i = 0; i < 5; i++) {
		cin >> score;
		if (score < 40) {
			total += 40;
		}
		else { total += score; }
	}
	cout << total / 5 << endl;
}