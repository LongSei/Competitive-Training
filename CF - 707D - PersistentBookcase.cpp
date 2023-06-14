#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
#define ep emplace_back
const int MAX = 1e5 + 5;
vector<int> adjlist[MAX];

struct data {
	int t, x, y;
} query[MAX];

bitset<1005> S;
bitset<1005> f[1005];

int n, m, q, ans[MAX];
int cnt = 0;

void input() {
	cin >> n >> m >> q;
	for (int i = 1; i <= q; i++) {
		int t, x, y;
		cin >> t >> x;
		if (t == 4) {
			adjlist[x].ep(i);
			continue;
		}
		if (t <= 2) {
			cin >> y;
			query[i].t = t;
			query[i].x = x;
			query[i].y = y;
		}
		if (t == 3) {
			query[i].t = t;
			query[i].x = x;
		}
		adjlist[i - 1].ep(i);
	}
	for (int i = 1; i <= m; i++) {
		S[i] = 1;
	}
}

void dfs(int status) {
	ans[status] = cnt;
	for (int v : adjlist[status]) {
		int t = query[v].t;
		int x = query[v].x;
		int y = query[v].y;
		if (t == 0) {
			dfs(v);
		}
		if (t == 1) {
			int pre = f[x][y];
			if (pre == 0) {
				f[x][y] = 1;
				cnt++;
			} 
			dfs(v);
			if (pre == 0) {
				f[x][y] = 0;
				cnt--;
			}
		}
		if (t == 2) {
			int pre = f[x][y];
			if (pre == 1) {
				f[x][y] = 0;
				cnt--;
			}
			dfs(v);
			if (pre == 1) {
				f[x][y] = 1;
				cnt++;
			}
		}
		if (t == 3) {
			int pre = cnt;
			cnt -= f[x].count();
			f[x] ^= S;
			cnt += f[x].count();
			dfs(v);
			f[x] ^= S;
			cnt = pre;
		}
	}
}

void solve() {
	dfs(0);
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}
}

signed main() {
	faster;
	input();
	solve();
}
