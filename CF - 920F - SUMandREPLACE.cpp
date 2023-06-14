#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX = 3e5 + 1;
const int MAXI = 1e6 + 1;
int n, m, arr[MAX], t, l, r, st[MAX * 4], d[MAXI], x, y, maxi[MAX * 4];

void prepare() {
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            d[j]++;
        }
    }
}

void build(int v, int l, int r) {
	if (l == r) {
		st[v] = arr[l];
		maxi[v] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid + 1, r);
	st[v] = st[v * 2 + 1] + st[v * 2];
	maxi[v] = max(maxi[v * 2 + 1], maxi[v * 2]);
}

void update(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l) {
		return;
	}
	if (l <= tl && tr <= r) {
		if (maxi[v] <= 2) {
			return;
		}
		if (tr == tl) {
			st[v] = d[st[v]];
			maxi[v] = st[v];
			return;
		}
	}
	int mid = (tr + tl) / 2;
	update(v * 2, tl, mid, l, r);
	update(v * 2 + 1, mid + 1, tr, l, r);
	st[v] = st[v * 2 + 1] + st[v * 2];
	maxi[v] = max(maxi[v * 2 + 1], maxi[v * 2]);
}

int getans(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l) {
		return 0;
	}
	if (l <= tl && tr <= r) {
		return st[v];
	}
	int mid = (tl + tr) >> 1;
	return getans(v * 2, tl, mid, l, r) + getans(v * 2 + 1, mid + 1, tr, l, r);
}

signed main() {
	faster;
	prepare();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build(1,1,n);
	while (m--) {
		cin >> t >> x >> y;
		if (t == 1) {
			update(1,1,n,x,y);
		}
		else {
			cout << getans(1,1,n,x,y) << endl;
		}
	}
}
