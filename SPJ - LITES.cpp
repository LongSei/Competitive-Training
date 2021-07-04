#include<bits/stdc++.h>
#define MAX 100007
#define int long long
using namespace std;
int N,M,plan,x,y;
int st[MAX * 4];
int lazy[MAX * 4];

void update(int i, int l, int r, int x, int y) {
	if (l > y || r < x) {
		return;
	}
	if (l >= x && r <= y) {
		st[i] = (r - l + 1) - st[i];
		lazy[i] = 1 - lazy[i];
		return;
	}
	int mid = (l + r) / 2;
	if (lazy[i] == 1) {
		update(i * 2, l, mid, l, mid);
		update(i * 2 + 1, mid + 1, r, mid + 1, r);
		lazy[i] = 1 - lazy[i];
	}
	update(i * 2, l, mid, x, y);
	update(i * 2 + 1, mid + 1, r, x, y);
	st[i] = st[i * 2] + st[i * 2 + 1];
}

long long get(int i, int l, int r, int x, int y) {
	if (l > y || r < x) {
		return 0;
	}
	if (l >= x && r <= y) {
		return st[i];
	}
	int mid = (l + r) / 2;
	if (lazy[i] == 1) {
		update(i * 2, l, mid, l, mid);
		update(i * 2 + 1, mid + 1, r, mid + 1, r);
		lazy[i] = 1 - lazy[i];
	}
	return get(i * 2, l, mid, x, y) + get(i * 2 + 1, mid + 1, r, x, y);
}

signed main() {
	cin >> N >> M;
	while (M--) {
		cin >> plan >> x >> y;
		if (plan == 0) {
			update(1,1,N,x,y);
		}
		else {
			cout << get(1,1,N,x,y) << endl;
		}
	}
}
