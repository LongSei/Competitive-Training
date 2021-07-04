#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 50001
#define INF 10000000
int n, m, ktr, u, v, k;
int seg[MAXN];

struct Node {
	int lazy;
	int val;
} node[MAXN * 4];

void down(int id) {
	int t = node[id].lazy;
	node[id * 2 + 1].lazy += t;
	node[id * 2 + 1].val += t;
	node[id * 2 + 2].lazy += t;
	node[id * 2 + 2].val += t;
	node[id].lazy = 0;
}

void update(int id, int tl, int tr, int l, int r, int val) {
	if (tl > r || tr < l) {
		return;
	}
	if (l <= tl && tr <= r) {
		node[id].lazy += val;
		node[id].val += val;
		return;
	}
	else {
		down(id);
		int mid = (tl + tr) / 2;
		update(id * 2 + 1, tl, mid, l, r, val);
		update(id * 2 + 2, mid + 1, tr, l, r, val);
		node[id].val = max(node[id * 2 + 1].val, node[id * 2 + 2].val);
	}
}

int getans(int id, int tl, int tr, int l, int r) {
	if (r < tl || tr < l) {
		return -INF;
	}
	if (l <= tl && tr <= r) {
		return node[id].val;
	}
	else {
		down(id);
		int mid = (tl + tr) / 2;
		return max(getans(id * 2 + 1, tl, mid, l, r), getans(id * 2 + 2, mid + 1, tr, l, r));
	}
}

signed main() {
	cin >> n >> m;
	while (m--) {
		cin >> ktr;
		if (ktr == 0) {
			cin >> u >> v >> k;
			update(1,1,n,u,v,k);
		}
		else {
			cin >> u >> v;
			cout << getans(1,1,n,u,v) << endl;
		}
	}
}
