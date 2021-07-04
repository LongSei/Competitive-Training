#include<bits/stdc++.h>
using namespace std;
int test, a, b;
#define int long long
const int MAX = 1e8;

bool isPrime(int a) {
	if (a == 1 || a == 0) {
		return false;
	}
	else {
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0) {
				return false;
			}
		}
	}
	return true;
} 

signed main() {
	cin >> test;
	while (test--) {
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			if (isPrime(i) == true) {
				cout << i << endl;
			}
		}
		cout << endl;
	}
}
