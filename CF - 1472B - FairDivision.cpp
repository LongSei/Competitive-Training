#include<bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;
	while (test > 0) {
		int candy;
		cin >> candy;
		int keo;
		int sum = 0;
		int number1 = 0, number2 = 0;
		for (int i = 1; i <= candy; i++) {
			cin >> keo;
			sum += keo;
			if (keo == 1) {
				number1++;
			}
			else {
				number2++;
			}
		}
		if (sum % 2 != 0) {
			cout << "NO" << endl;
		}
		else {
			int tong = sum / 2;
			while (number2 > 0 && tong > 1) {
				number2--;
				tong -= 2;
			} 
			while (number1 > 0 && tong > 0) {
				number1--;
				tong--;
			}
			if (tong == 0) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		test--;
	}
}
