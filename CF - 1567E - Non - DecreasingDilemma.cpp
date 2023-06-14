#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 2e5 + 5;
int n, query, arr[MAX];
struct Node {
	int total; 
	int left; 
	int right;
	Node (int total = 0, int left = 0, int right = 0) : total(total), left(left), right(right) {} 
};
Node st[MAX * 4];

void update(int v, int tl, int tr, int pos) {
	if (tl > pos || tr < pos) {
		return;
	}
	if (tl == pos && tr == pos) {
		st[v].total = 1;
		st[v].left = 1;
		st[v].right = 1;
		return;
	}
	int mid = (tl + tr) >> 1;
	if (pos <= mid) update(v * 2 + 1, tl, mid, pos);
	else update(v * 2 + 2, mid + 1, tr, pos);
	if (arr[mid] <= arr[mid + 1]) {
		st[v].total = st[v * 2 + 1].total + st[v * 2 + 2].total + (st[v * 2 + 1].right * st[v * 2 + 2].left);	
		st[v].left = st[v * 2 + 1].left == mid - tl + 1 ? st[v * 2 + 1].left + st[v * 2 + 2].left : st[v * 2 + 1].left;
		st[v].right = st[v * 2 + 2].right == tr - (mid + 1) + 1 ? st[v * 2 + 2].right + st[v * 2 + 1].right : st[v * 2 + 2].right;
	}
	else {
		st[v].total = st[v * 2 + 1].total + st[v * 2 + 2].total;
		st[v].left = st[v * 2 + 1].left;
		st[v].right = st[v * 2 + 2].right;
	}
}

Node getans(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l) {
		return Node(0, 0, 0);
	}
	if (l <= tl && tr <= r) {
		return st[v];
	}
	int mid = (tl + tr) >> 1;
	Node low = getans(v * 2 + 1, tl, mid, l, r);
	Node high = getans(v * 2 + 2, mid + 1, tr, l, r);
	int res, nl, nr;
	if (arr[mid] <= arr[mid + 1]) {
		res = low.total + high.total + (low.right * high.left);	
		nl = low.left == mid - tl + 1 ? low.left + high.left : low.left;
		nr = high.right == tr - (mid + 1) + 1 ? high.right + low.right : high.right;
	}
	else {
		res = low.total + high.total;
		nl = low.left;
		nr = high.right;
	}
	return Node(res, nl, nr);
}

signed main() {
	faster;
	cin >> n >> query;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		update(1, 1, n, i);
	}
	for (int i = 1; i <= query; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos, val;
			cin >> pos >> val;
			arr[pos] = val;
			update(1, 1, n, pos);
		}
		else {
			int l, r; cin >> l >> r;
			cout << getans(1, 1, n, l, r).total << endl;
		}
	}
}
