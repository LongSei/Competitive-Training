#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int test, k, city, edg, u, v, w, cost;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef pair<int, ii> iii;
vector<iii> adjlist[MAX];
priority_queue<iii, vector<iii>, greater<iii> > pq;

int main() {
	cin >> test;
	while (test--) {
		cin >> k >> city >> edg;
		for (int i = 1; i <= city; i++) {
			adjlist[i].clear();
		}
		while (edg--) {
			cin >> u >> v >> w >> cost;
			adjlist[u].push_back(make_pair(v, ii(w, cost)));
		}
		pq = priority_queue<iii, vector<iii>, greater<iii> >();
		pq.push(make_pair(0, ii(0, 1)));
		bool found = false;
		while (pq.empty() == false) {
			iii vo = pq.top();
			pq.pop();
			w = vo.first;
			cost = vo.second.first;
			u = vo.second.second;
			if (u == city) {
				found = true;
				break;
			}
			else {
				for (int i = 0; i < adjlist[u].size(); i++) {
					iii vu = adjlist[u][i];
					v = vu.first;
					int vw = vu.second.first;
					int vcost = vu.second.second;
					if (cost + vcost <= k) {
						pq.push(make_pair(vw + w, ii(vcost + cost, v)));
					}
				}
			}
		}
		if (found == true) {
			cout << w << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}
