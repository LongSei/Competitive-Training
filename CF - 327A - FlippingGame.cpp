#include<bits/stdc++.h>
using namespace std;

int number;
int a[101];
int one = 0;
int sum = 0;
int ans = 0;

int main() {
	cin >> number;
	for (int i = 0 ; i  <number; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			one++;
		}
	}
	for (int i = 0 ; i  <number; i++) {
		if (a[i] == 0) {
			sum++;
		}
		else {
			sum--;
		}
		if (sum < 0) {
			sum = 0;
		}
		ans = max(ans, sum);
	}
	if (one == number) {
		cout << number - 1;
	}
	else {
		cout << one + ans;
	}
}
