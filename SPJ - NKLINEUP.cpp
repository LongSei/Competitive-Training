#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define INF 10000001
#define int long long
int seg[MAX], n, q, a, b, mini = 0, maxi = INF;
pair<int, int> st[4 * MAX];

void build(int a[], int v, int l, int r) {
	if (l == r) {
		st[v].first = st[v].second = a[l];
	}
	else {
		int mid = (l + r) / 2;
		build(a, v * 2 + 1, l, mid);
		build(a, v * 2 + 2, mid + 1, r);
		st[v].first = min(st[v * 2 + 1].first, st[v * 2 + 2].first);
		st[v].second = max(st[v * 2 + 1].second, st[v * 2 + 2].second);
	}
}

void getans(int v, int tl, int tr, int l, int r) {
	if (r < tl || l > tr) {
		return;
	}
	if (tl >= l && tr <= r) {
		mini = min(mini, st[v].first);
		maxi = max(maxi, st[v].second);
		return;
	}
	int mid = (tl + tr) / 2;
	getans(v * 2 + 1, tl, mid, l, r);
	getans(v * 2 + 2, mid + 1, tr, l, r);
}

signed main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> seg[i];
	}
	build(seg, 1, 1, n);
	for (int i = 1; i <= q; i++) {
		cin >> a >> b;
		mini = INF;
		maxi = 0;
		getans(1,1,n,a,b);
		cout << maxi - mini << endl;
	}
}
