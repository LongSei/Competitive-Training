#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 15;

string s, a, b;
int kmp[N];

int main() {
	cin >> a >> b;
	s = b + '#' + a;
	kmp[0] = 0;
	for (int i = 1; i <= s.size() - 1; i++) {
		int j = kmp[i - 1];
		while (j > 0 && s[j] != s[i]) {
			j = kmp[j-1];
		}
		if (s[j] == s[i]) {
			j++;
		}
		kmp[i] = j;
	}
	for (int i = b.size() + 1; i <= s.size() - 1; i++) {
		if (kmp[i] == b.size()) {
			cout << i - 2 * b.size() + 1 << " ";
		}
	}
}
