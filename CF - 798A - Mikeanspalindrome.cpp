#include<bits/stdc++.h>
using namespace std;
string s;
int dem = 0;

int main() {
	cin >> s;
	if (s.size() % 2 == 0) {
		for (int i = 0; i <= (s.size() / 2) - 1; i++) {
			//cout << s[i] << " " << s[s.size() - i - 1] << endl;
			if (s[i] != s[s.size() - i - 1]) {
				dem++;
			}
		}
		if (dem == 1) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else if (s.size() == 1) {
		cout << "YES";
	}
	else {
		for (int i = 0; i <= (s.size() - 1) / 2 - 1; i++) {
			//cout << s[i] << " " << s[s.size() - 1 - i] << endl;
			if (s[i] != s[s.size() - 1 - i]) {
				if (s[i] != s[s.size() - 1 - i]) {
					dem++;
				}
			} 
		}
		if (dem <= 1) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
}
