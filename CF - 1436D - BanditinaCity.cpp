#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int n, weight[MAX], setsize[MAX], setweight[MAX];
vector<int> adjlist[MAX];

void dfs(int pos) {
	setweight[pos] = weight[pos];
	if (adjlist[pos].size() == 0) {
		setsize[pos] = 1;
	}
	for (int v : adjlist[pos]) {
		dfs(v);
		setweight[pos] += setweight[v];
		setsize[pos] += setsize[v];
	}
}

void input() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		adjlist[x].emplace_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (setweight[i] % setsize[i] == 0) {
			ans = max(ans, setweight[i] / setsize[i]);
		}
		else {
			ans = max(ans, setweight[i] / setsize[i] + 1);
		}
	}
	cout << ans;
}

signed main() {
	faster;
	input();
}
