#include<bits/stdc++.h> 
using namespace std;
int s[1000];
int number; 
int lastminute(int i) {
		if (i == number - 1) {
			if (s[i] + 15 <= 90) {
				return s[i] + 15; 
			}
			else {
				return 90;
			}
		}
		else {
			if (s[i + 1] - s[i] > 15) {
				return s[i] + 15;
			}
			else {
				return lastminute(i + 1);
			}
		}
}

int main() {
	cin >> number;
	for (int i = 0 ; i < number; i++) {
		cin >> s[i];
	}
	int sum = 0;
	if (s[0] > 15) {
		cout << 15;
		return 0;
	}
	else {
		cout << lastminute(0);
	}
}
