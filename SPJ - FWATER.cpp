#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 300 * 300 + 300 + 1;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<pair<int, ii> > adjlist;
int n, w, kq = 0;
vi pset(301);

void initset(int i) {
	pset.assign(i + 2, 0);
	for (int j = 1; j <= i + 1; j++) {
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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	initset(n);
	for (int i = 1; i <= n; i++) {
		cin >> w;
		adjlist.push_back(make_pair(w, ii(i, n + 1)));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w;
			adjlist.push_back(make_pair(w, ii(i, j)));
		}
	}
	sort(adjlist.begin(), adjlist.end());
	for (int i = 0; i < adjlist.size(); i++) {
		if (!issameset(adjlist[i].second.second, adjlist[i].second.first)) {
			kq += adjlist[i].first;
			unionset(adjlist[i].second.second, adjlist[i].second.first);
		}
	}
	cout << kq;
}
