#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 2e5;
int isPrime[MAX], a, b;

void build() {
	isPrime[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i] == 0) {
		//	cout << i << " B: ";
			int q = 2 * i;
			while (q <= MAX) {
		//		cout << q << " ";
				isPrime[q] = i;
				q += i;
			}
		//	cout << endl;
		}
	}
} 

signed main() {
	build();
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		//cout << "ASN: " << isPrime[i] << endl;
		if (isPrime[i] == 0) {
			cout << i << endl;
		}
	}
}
