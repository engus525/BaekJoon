#include <iostream>
using namespace std;

void d() {
	int num[10000] = { 0, };
	int numtok[5] = { 0, };
	for (int i = 1; i <= 10000; i++) {
		
		if (i == 10000) { numtok[0] = 1; }
		else if (i >= 1000 && i < 10000) {
			numtok[0] = i / 1000;
			numtok[1] = (i % 1000) / 100;
			numtok[2] = (i % 100) / 10;
			numtok[3] = i % 10;
		}
		else if (i >= 100 && i < 1000) {
			numtok[0] = i / 100;
			numtok[1] = (i % 100) / 10;
			numtok[2] = i % 10;
		}
		else if (i >= 10 && i < 100) {
			numtok[0] = i / 10;
			numtok[1] = i % 10;
		}
		else { numtok[0] = i; }
		int sum = i;
		for (int j = 0; j < 5; j++) {
			sum += numtok[j];			
		}
		if (sum <= 10000) {
			num[i] = sum;
		}
	}for (int i = 1; i <= 10000; i++) {
		bool check = false;
		for (int j = 0; j < 10000; j++) {
			if (num[j] == i) { 
				check = true;
				break;
			}
			
		}
		if (check == false) { cout << i << endl; }
	}
}

int main() {
	d();	
}