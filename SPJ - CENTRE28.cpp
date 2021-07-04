#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, u, v, w, cnt = 0;
const int MAX = 30001;
const int INF = 2e9;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<vector<ii> > adjlist;
typedef priority_queue< ii, vector< ii >, greater< ii > > pq;
int dis1[MAX], disn[MAX], cnt1[MAX], cntn[MAX];
 
void dtr1(int s, int f) {
	for (int i = 1; i <= n; i++) {
		dis1[i] = INF;
	}
	memset(cnt1, 0, sizeof cnt1);
	dis1[s] = 0;
	cnt1[s] = 1;
	pq heap;
	heap.push(ii(0, s));
	while (heap.empty() == false) {
		ii vu = heap.top();
		heap.pop();
		int n = vu.second;
		int m = vu.first;
		if (n == f) {
			break;
		}
		if (m != dis1[n]) {
			continue;
		}
		if (m == dis1[n]) {
			for (int i = 0 ; i < adjlist[n].size(); i++) {
				ii vo = adjlist[n][i];
				if (vo.first + dis1[n] == dis1[vo.second]) {
					cnt1[vo.second] += cnt1[n];
				}
				if (vo.first + dis1[n] < dis1[vo.second]) {
					dis1[vo.second] = dis1[n] + vo.first;
					cnt1[vo.second] = cnt1[n];
					heap.push(ii(dis1[vo.second], vo.second));
				}
			}
		}
	}
}
 
void dtrn(int st, int en) {
	for (int i = 1; i <= n; i++) {
		disn[i] = INF;
	}
	memset(cntn, 0, sizeof cntn);
	disn[st] = 0;
	cntn[st] = 1;
	pq heap;
	heap.push(ii(0, st));
	while (heap.empty() == false) {
		ii vo = heap.top();
		heap.pop();
		int n = vo.second;
		int m = vo.first;
		if (n == en) {
			break;
		}
		if (m != disn[n]) {
			continue;
		}
		if (m == disn[n]) {
			for (int i = 0 ; i < adjlist[n].size(); i++) {
				ii vo = adjlist[n][i];
				if (vo.first + disn[n] == disn[vo.second]) {
					cntn[vo.second] += cntn[n];
				}
				if (vo.first + disn[n] < disn[vo.second]) {
					disn[vo.second] = disn[n] + vo.first;
					cntn[vo.second] = cntn[n];
					heap.push(ii(disn[vo.second], vo.second));
				}
			}
		}
	}
}
 
void readinput() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	adjlist.assign(n + 1, vii());
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		adjlist[u].push_back(ii(w,v));
		adjlist[v].push_back(ii(w,u));
	}
}
 
void solve() {
	readinput();
	dtr1(1,n);
	dtrn(n,1);
	for (int i = 2 ; i < n; i++) {
		if (dis1[i] + disn[i] != dis1[n] || cnt1[i] * cntn[i] != cnt1[n]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 2; i < n; i++) {
		if (dis1[i] + disn[i] != dis1[n] || cnt1[i] * cntn[i] != cnt1[n]) {
			cout << i << endl;
		}
	}
}
 
signed main() {
	solve();
	return 0;
}
