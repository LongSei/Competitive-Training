#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX = 1e4 + 1;
int n, m, u, v, w, ans = 0;
typedef vector<int> vi;
typedef pair<int, int> ii;
vector< pair<int, ii> > edgelist;
vi pset(MAX);

void initset(int i) {
	pset.assign(i + 1, 0);
	for (int j = 1; j <= i; j++) {
		pset[j] = j;
	}
}

int findset(int i) {
	if (pset[i] == i) {
		return i;
	}
	else {
		return findset(pset[i]);
	}
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
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		edgelist.push_back(make_pair(w, ii(u, v)));
	}
	sort(edgelist.begin(), edgelist.end());
	for (int i = 0; i < edgelist.size(); i++) {
		pair<int, ii> vu = edgelist[i];
		if (issameset(vu.second.second, vu.second.first) == false) {
			if (vu.first > ans) {
				ans = vu.first;
			}
			unionset(vu.second.second, vu.second.first);
		}
	}
	cout << ans;
}
