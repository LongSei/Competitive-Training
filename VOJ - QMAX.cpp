#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX = 50005;
int seg[MAX];
int node, updatetime;
int u,v,k;
int p,l,r;
int ST[MAX * 4];
int ans = 0;

void build(int arr[], int v, int tl, int tr) {
    if (tl == tr) {
        ST[v] = arr[tl];
        return;
    }
    int mid = (tl + tr) >> 1;
    build(arr, v * 2, tl, mid);
    build(arr, v * 2 + 1, mid + 1, tr);
    ST[v] = max(ST[v * 2], ST[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) {
        return -1;
    }
    if (l <= tl && tr <= r) {
        return ST[v];
    }
    int mid = (tl + tr) >> 1;
    return max(get(v * 2, tl, mid, l, r), get(v * 2 + 1, mid + 1, tr, l, r));
}

signed main() {
	cin >> node >> updatetime;
	for (int i = 1; i <= node; i++) {
		seg[i] = 0;
	}
    for (int i = 1; i <= updatetime; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        seg[u] += k;
        seg[v + 1] -= k;
    }
    for (int i = 1; i <= node; i++) {
        seg[i] += seg[i - 1];
    }
	build(seg, 1, 1, node);
	cin >> p;
	while (p--) {
		cin >> l >> r;
 		cout << get(1,1,node,l,r) << endl;
	}
}
