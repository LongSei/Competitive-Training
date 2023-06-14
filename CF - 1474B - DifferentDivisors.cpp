#include<bits/stdc++.h>
using namespace std;

int test;
int d;

bool prime(int i) {
	if (i == 2) {
		return true;
	}
	for (int j = 2; j < i; j++) {
		if (i % j == 0) {
			return false;
		}
	}
	return true;
}

int nextprime(int i) {
	if (i == 2) {
		return 3;		
	}
	int now = i + d;
	while (prime(now) == false) {
		now++;
	}
	return now;
}

int main() {
	cin >> test;
	while (test--) {
		cin >> d;
		int ans;
		int second = 1 + d;
		while (prime(second) == false) {
			second++;
		}
		ans = second * nextprime(second);
		cout << ans << endl;
	}
}
