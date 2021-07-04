#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 2e5 + 1;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int kq, n, m, u, v, w;
vector<pair<int, ii> > adjlist;
vi pset(MAX);

void initset(int i) {
	pset.assign(i, 0);
	for (int j = 0; j < i; j++) {
		pset[j] = j;
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
	cin >> n >> m;
	initset(n);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adjlist.push_back(make_pair(w, ii(u,v)));
	}
	sort(adjlist.begin(), adjlist.end());
	for (int i = 0; i < m; i++) {
		pair<int, ii> vu = adjlist[i];
		if (issameset(vu.second.first, vu.second.second) == false) {
			kq += vu.first;
			unionset(vu.second.first, vu.second.second);
		}
	}
	cout << kq;
}
