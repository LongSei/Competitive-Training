#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 30 * 1e5 + 5;
int trie[MAX][2], n, arr[MAX], cnt = 0;

int getbit(int n, int k) {
	return (n >> (k - 1)) & 1;
}

void add(int val) {
	int nw = 0;
	for (int bit = 30; bit >= 1; bit--) {
		if (trie[nw][getbit(val, bit)] == 0) {
			trie[nw][getbit(val, bit)] = ++cnt;
		}
		nw = trie[nw][getbit(val, bit)];
	}
}

int getans(int val) {
	int ans = 0;
	int nw = 0;
	for (int bit = 30; bit >= 1; bit--) {
		int nbit = getbit(val, bit);
		if (nbit == 1 && trie[nw][1 - nbit] == 0) {
			ans += (1 << (bit - 1));
		}
		if (nbit == 0 && trie[nw][1 - nbit] != 0) {
			ans += (1 << (bit - 1));
		}
		nw = trie[nw][nbit];
	}
	return ans ^ val;
}

signed main() {
	faster;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		add(arr[i]);
	}
	int ans = INT_MAX;
	for (int i= 1; i <= n; i++) {
		ans = min(ans, getans(arr[i]));
	}
	cout << ans;
}
