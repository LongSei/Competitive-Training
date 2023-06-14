#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 100005;
int trie[MAX][2], n;
pair<int, int> siz[MAX]; int cnt = 0;
int mark[MAX]; bool check[MAX]; int to;

bool add(int pos, int val) {
	if (val == 0) {
		check[pos] = true;
		mark[pos] = to;
		return true;
	}
	for (int i = 0; i <= 1; i++) {
		if (check[trie[pos][1]] == true && check[trie[pos][0]] == true) {
			return false;
		}
	}
	bool ok = false;
	for (int i = 0; i <= 1; i++) {
		if (check[trie[pos][i]] == true) {
			continue;
		}
		if (trie[pos][i] == 0) {
			trie[pos][i] = ++cnt;
		}
		if (add(trie[pos][i], val - 1) == true) {
			ok = true;
			break;
		}
	}
	if (ok == false) {
		return false;
	}
	if (check[trie[pos][1]] == true && check[trie[pos][0]] == true) {
		check[pos] = true;
	}
	return true;
}

vector<pair<int, string>> result;
void dfs(int pos, string res) {
	for (int i = 0; i <= 1; i++) {
		if(trie[pos][i] != 0) {
			dfs(trie[pos][i], res + to_string(i));
		}
	}
	if (mark[pos] != 0) {
		result.push_back(pair<int,string>(mark[pos], res));
		return;
	}
}

signed main() {
	faster;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> siz[i].first;
		siz[i].second = i;
	}
	sort(siz + 1, siz + 1 + n);
	for (int query = 1; query <= n; query++) {
		to = siz[query].second;
		if (add(0, siz[query].first) == false) {
			cout << "NO";
			return 0;
		}
	}
	dfs(0, "");
	sort(result.begin(), result.end());
	cout << "YES" << endl;
	for (auto v : result) {
		cout << v.second << endl;
	}
}
