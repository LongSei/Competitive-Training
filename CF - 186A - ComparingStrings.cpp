#include<bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int cnt = 0;
	int checkchr = 0;
	bool check[10000];
	if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				cnt++;
				if (check[s1[i]] == false) {
					check[s1[i]] = true;
					checkchr++;
				}
				if (check[s2[i]] == false) {
					check[s2[i]] = true;
					checkchr++;
				}
				
			}
		}
		if (cnt == 2 && checkchr == 2) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
}
