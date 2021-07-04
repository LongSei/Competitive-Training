#include<bits/stdc++.h>
#define MAX 50001
using namespace std;
int seg[MAX];
int node, updatetime;
int u,v,k;
int p,l,r;
int ST[MAX * 4];
int ans = 0;

void build(int a[], int v, int st, int en) {
	if (st == en) {
		ST[v] = a[st];		
	}
	else {
		int nw = (st + en) / 2;
		build(a,v * 2,st,nw);
		build(a,v * 2 + 1,nw + 1,en);
		ST[v] = max(ST[v * 2],ST[v * 2 + 1]);
	}
}

void get(int id, int l, int r, int u, int v) {
	if (v < l || r < u) {
		return;
	}
	if (u <= l && r <= v) {
		ans = max(ans, ST[id]);
		return;
	}
	int mid = (l + r) / 2;
	get(id * 2, l, mid , u, v);
	get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
	cin >> node >> updatetime;
	for (int i = 0 ; i < node; i++) {
		seg[i] = 0;
	}
	while (updatetime--) {
		cin >> u >> v >> k;
		for (int i = u - 1; i < v; i++) {
			seg[i] += k;
		}
	}
	build(seg, 1, 0, node - 1);
	cin >> p;
	while (p--) {
		cin >> l >> r;
 		ans = 0;
 		get(1,1,node,l,r);
		cout<<ans<<endl;
	}
}
