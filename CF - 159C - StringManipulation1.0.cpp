#include<bits/stdc++.h>
using namespace std;

int k;
string s;
int noerase;
int pos;
char era;

void xoapt(int pos) {
	for (int i = pos; i < s.size(); i++) {
		s[i] = s[i + 1];
	}
}

int main() {
	cin >> k >> s >> noerase;
	string trash = s;
	while (k > 1) {
		s.append(trash);
		k--;
	}
	while (noerase > 0) {
		cin >> pos >> era;
		int cnt = 1;
		for (int i = 0; i < s.size(); i++) {
			if (era == s[i]) {
				if (cnt == pos) {
					xoapt(i);
					break;
				}
				else {
					cnt++;
				}
			}
		}
		noerase--;
	}
	cout << s;
}
