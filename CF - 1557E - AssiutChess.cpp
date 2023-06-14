#include<bits/stdc++.h>
using namespace std;
int curry = 1; int cnt = 0;
string input(int x, int y) {
	cnt++; assert(cnt <= 130);
	cout << x << " " << y << endl;
	curry = y;
	string s; cin >> s;
	return s;
}

bool sub(int currow) {
	string s;
	if (curry == 8) {
		for (int i = 7; i >= 1; i--) {
			s = input(currow, i);
			if (s == "Done") {
				return true;
			}
			if (s[0] == 'U') {
				return sub(currow);
			}
			if (s[0] == 'D') {
				return false;
			}
		}
		return false;
	}
	else {
		if (curry != 1) {
			s = input(currow, 1);
			if (s == "Done") {
				return true;
			}
			if (s[0] == 'U') {
				return sub(currow);
			}
			if (s[0] == 'D') {
				return false;
			}
		}
		for (int i = 2; i <= 8; i++) {
			s = input(currow, i);
			if (s == "Done") {
				return true;
			}
			if (s[0] == 'U') {
				return sub(currow);
			}
			if (s[0] == 'D') {
				return false;
			}
		}
		return false;
	}
}

void solve() {
	string s; curry = 1; cnt = 0;
	for (int i = 1; i <= 8; i++) {
		s = input(i, curry);
		if (s == "Done") {
			return;
		}
		if (sub(i)) {
			return;
		}
	}
}

int main() {
	int test; cin >> test;
	while(test--) solve();
}
