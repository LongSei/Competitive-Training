#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAX = 1001;
int n, m, a, b, pset[MAX], sizeset[MAX], thu[MAX], numberdisjoinset, ans = 0;
char pb;

void initset(int a) {
	numberdisjoinset = a;
	for (int i = 1; i <= a; i++) {
		pset[i] = i;
		sizeset[i] = 1;
		thu[i] = 0;
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
	if (issameset(findset(i), findset(j)) == false) {
		numberdisjoinset--;
		sizeset[j] += sizeset[i];
		pset[findset(i)] = findset(j);
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	initset(n);
	for (int i = 1; i <= m; i++) {
		cin >> pb >> a >> b;
		if (pb == 'F') {
			unionset(a, b);	
		}
		else {
			if (thu[a] != 0) {
				unionset(thu[a], b);
			}
			if (thu[b] != 0) {
				unionset(thu[b], a);
			}
			thu[a] = b;
			thu[b] = a;
		}
	}
	cout << numberdisjoinset;
}
