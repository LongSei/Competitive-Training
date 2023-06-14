#include<bits/stdc++.h>
using namespace std;
int student;
int st[2001];

void sort() {
	for (int i = 1; i <= student; i++ ) {
		for (int j = i + 1; j <= student; j++) {
			if (st[i] < st[j]) {
				int trash = st[i];
				st[i] = st[j];
				st[j] = trash;
			}
		}
	}
}

int main() {
	cin >> student;
	int sti[2001];
	for (int i = 1; i <= student; i++) {
		cin >> st[i];
		sti[i] = st[i];
	}
	int cnt[2001];
	int dem = 1;
	int demcho = 0;
	sort();
	int now = st[0];
	for (int i = 1; i <= student; i++) {
		if (st[i] == now) {
			cnt[st[i]] = dem;
			demcho++;
		}
		else {
			now = st[i];
			dem += demcho;
			cnt[st[i]] = dem;
			demcho = 1;
		}
	}
	for (int i = 1; i <= student; i++) {
		cout << cnt[sti[i]] << " ";
	}
}
