#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int prefix[MAX], cnt[MAX];

void solve() {
	string s; cin >> s;
	for (int i = 1; i <= s.size() - 1; i++) {
		int k = prefix[i - 1];
		while (k > 0 && s[i] != s[k]){ 
			k = prefix[k - 1];
		}
		prefix[i] = k + (s[i] == s[k]);
	}
	vector<int> result;
	result.push_back(s.size());
	int k = s.size();
	while (k) {
		k = prefix[k - 1];
		if (k != 0) result.push_back(k);
	}
	reverse(result.begin(), result.end());
	for (int i = 0; i < s.size(); i++) {
		cnt[prefix[i]]++;
	}
	for (int i = s.size() - 1; i >= 1; i--) {
		cnt[prefix[i - 1]] += cnt[i];
	}
	cout << result.size() << endl;
	for (auto v : result) {
		cout << v << " " << cnt[v] + 1 << endl;
	}
}

signed main() {
	faster;
	solve();
}
