#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 5005;
int test; int n; int total_depth;
int ans[MAX], depth[MAX];
queue<int> q;
int parent[MAX];
set<int> adjlist[MAX];

void reset(int n) {
	q = queue<int>();
	for (int i = 0; i <= n + 1; i++) {
		depth[i] = 0;
		parent[i] = 0;
		adjlist[i].clear();
	}
}

void solve() {
	cin >> n >> total_depth; reset(n);
	for (int i = 1; i <= n; i++) {
		depth[i] = i - 1;
		parent[i] = i - 1;
		adjlist[i - 1].insert(i);
	}
	int maxitotal = n * (n - 1) / 2;
	int minitotal = 0; int lg = 0;
	int t = 0, nw = 1;
	while (t < n) {
		t += nw;
		nw *= 2;
		lg++;
	}
	if ((1 << lg) > n) {
		for (int i = 1; i <= lg - 1; i++) {
			minitotal += (i - 1) * (1 << (i - 1));
		}
		minitotal += (lg - 1) * (n - (t - (nw / 2)));
	}
	else {
		for (int i = 0; i <= lg - 1; i++) {
			minitotal += i * (1 << i);
		}
	}
	if (total_depth > maxitotal || total_depth < minitotal) {
		cout << "NO" << endl;
		return;
	}
	q.push(1);
	int nwtotal = maxitotal;
	int last_node = -1, last_depth = -1;
	for (int i = n; i >= 1; i--) {
		int to = q.front();
		int sub = depth[i] - depth[to] - 1;
		if (nwtotal - sub >= total_depth) {
			nwtotal -= sub;
			parent[i] = to;
			depth[i] = depth[to] + 1;
			adjlist[to].insert(i);
			adjlist[i].clear();
			if (adjlist[to].size() == 2) {
				q.pop();
				for (auto v : adjlist[to]) {
					q.push(v);
				}
			}
		}
		else {
			depth[i] = depth[i] - (nwtotal - total_depth);
			for (int k = 1; k <= i; k++) {
				if (depth[k] == depth[i] - 1 && adjlist[k].size() < 2) {
					parent[i] = k;
					adjlist[i].clear();
					adjlist[k].insert(i);
					break;
				}
			}
			break;
		}
		if (nwtotal == total_depth) {
			break;
		}
	}
	cout << "YES" << endl;
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << " ";
	}
	cout << endl;
}

signed main() {
	faster;
	cin >> test;
	while (test--) {
		solve();
	}
}
