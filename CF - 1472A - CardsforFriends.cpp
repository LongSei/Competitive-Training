#include<bits/stdc++.h>
using namespace std;

int test;
int w,h,n;

int cnt(int w) {
	int buf = 1;
	while (w % 2 == 0) {
		w /= 2;
		buf *= 2;
	}
	return buf;
}

int main() {
	cin >> test;
	while (test > 0) {
		cin >> w >> h >> n;
		int paper = 1 * cnt(w) * cnt(h);
		if (paper >= n) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		test--;
	}
}
