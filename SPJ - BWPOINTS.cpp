#include<bits/stdc++.h>
using namespace std;
#define int long long
#define val first
#define trd second
typedef pair<int, int> ii;
const int MAX = 2e5 + 1;
int n, dem = 0, now;
ii node[MAX];
 
bool cmp(ii a, ii b) {
	return a.val < b.val;
}
 
 
signed main() {
	cin >> n;
	for (int i = 1; i <= n * 2; i++) {
		cin >> node[i].val;
		if (i <= n) {
			node[i].trd = 1;
		}
		else {
			node[i].trd = 0;
		}
	}
	sort(node + 1, node + 1 + (2 * n), cmp);
	now = node[1].trd;
	for (int i = 2; i <= 2 * n ;i++) {
		if (now + node[i].trd == 1) {
			dem++;
			now = -1;
		}
		else {
			now = node[i].trd;
		}
	}
	cout << dem;
}
