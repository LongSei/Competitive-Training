#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, k;

signed main() {
	faster;
	cin >> n >> k;
	string t; cin >> t;
	queue<string> q; set<string> s;
	q.push(t);
	s.insert(t);
	int ans = 0;
	int total = 1;
	while (q.empty() == false && total < k) {
		string to_check = q.front();
		q.pop();
		for (int i = 0; i < to_check.size() && total < k; i++) {
			string nw = to_check;
			nw.erase(i, 1);
			if (s.count(nw) == 0) {
				s.insert(nw);
				total += 1;
				ans += n - nw.size();
				q.push(nw); 
			}
			
		}
	}
	if (total != k) {
		cout << -1;
		return 0;
	}
	cout << ans;
}
