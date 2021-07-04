#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAX = 10001;
vi pset(MAX);
int u, v, s, test;

void initset(int a) {
	pset.assign(a + 1, 0);
	for (int i = 1; i <= a; i++) {
		pset[i] = i;
	}
}

int findset(int i) {
	if (pset[i] == i) {
		return i;
	}
	return findset(pset[i]);
}

bool issameset(int i, int j) {
	if (findset(i) == findset(j)) {
		return true;
	}
	return false;
}

void unionset(int i, int j) {
	pset[findset(i)] = findset(j);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> test;
	initset(MAX);
	while (test--) {
		cin >> u >> v >> s;
		if (s == 1) {
			unionset(u, v);
		}
		else {
			cout << issameset(u, v) << endl;
		}
	}
}
