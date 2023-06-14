#include<bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin >> k;
	string s;
	cin >> s;
	int cnt = 0;
	int lent = 1;
	while (lent <= s.size()) {
		for (int i = 0; i < s.size() - lent + 1; i++) {
			int ct;
			if (s[i] == '1') {
				ct = 1;
			}
			else {
				ct == 0;
			} 
			for (int j = i + 1; j < i + lent; j++) {
				if (s[j] =='1') {
					ct++;
				}
			}
			if (ct == k) {
				cnt++;
			}
			ct = 0;
		}
		lent++;
	}
	cout << cnt;
}
