#include<bits/stdc++.h>
using namespace std;
 
int main() {
	string s;
	cin >> s;
	int cnt0 = 0;
	int begin,begin2;
	int x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			x++;
		}
	}
	if (x > 0) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				cout << "1";
				begin = i + 1;
				break;
			}
		}
		for (int i = begin; i < s.size(); i++) {
			if (s[i] == '0') {
				begin2 = i + 1;
				break;
			}
			else {
				cout << s[i];
			}
		}
		for (int i = begin2; i < s.size(); i++) {
			cout << s[i];
		}
	}
	else {
		for (int i = 1; i < s.size(); i++) {
			cout << s[i];
		}
	}
}
