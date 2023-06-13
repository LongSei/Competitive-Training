#include<bits/stdc++.h>
using namespace std;

// TEMPLATE FOR SOLVING PROBLEM // 
// #define endl '\n'
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 1e15 + 5;
const int MAX = 1e5 + 5;
const int mod = 1e9 + 7;

// TEMPLATE FOR DATA STRUCTURE AND ALGORITHM //	
int fast_pow(int n, int k) {
	int res = 1;
    while (k) {
        if (k & 1) {res = (res * n) % mod; k -= 1;}
        else {n = (n * n) % mod; k >>= 1;}
    }
    return res;
}
int GCD(int a, int b) {return b ? GCD (b, a % b) : a;}
int LCM(int a, int b) {return a * b / GCD(a, b);}
int GetBit(int k, int n) {return (n & (1 << k)) >> k;}

// MAIN CODE //
int n, k; 
int st[4194304];
int arr[MAX];
int masking[MAX];

void update(int v, int tl, int tr, int pos, int value) {
	if (pos < tl || pos > tr) {
		return;
	}
	if (tl == pos && pos == tr) {
		st[v] = value;
		return;
	}
	int mid = (tl + tr) >> 1;
	if (mid >= pos) {
		update(v * 2 + 1, tl, mid, pos, value);
	}
	else {
		update(v * 2 + 2, mid + 1, tr, pos, value);
	}
	st[v] = max(st[v * 2 + 1], st[v * 2 + 2]);
}

int query(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l) {
		return 0;
	}
	if (l <= tl && tr <= r) {
		return st[v];
	}
	int mid = (tl + tr) >> 1;
	return max(query(v * 2 + 1, tl, mid, l, r), query(v * 2 + 2, mid + 1, tr, l, r));
}

void solve() {
	cin >> n >> k;
	int maxValue = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		maxValue = max(maxValue, arr[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int maxi_pre = query(1, 1, maxValue, max(0, arr[i] - k), max(0, arr[i] - 1));
		ans = max(ans, maxi_pre + 1);
		update(1, 1, maxValue, arr[i], maxi_pre + 1);
	}
	cout << ans << endl;
}

signed main() {
	faster;
	int test = 1;
	// cin >> test; 
	while (test--) {
		solve();
	}
}
