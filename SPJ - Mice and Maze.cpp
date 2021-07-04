#include<bits/stdc++.h>
#define MAX 102
#define INF 1000000
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int mouse, start, toime, E, u, v, w, ans = 0;
int dis[MAX];
vector<vii> adjlist;
priority_queue<ii> pq;

int main() {
	cin >> mouse;
	adjlist.assign(mouse + 1, vii());
	cin >> start >> toime >> E;
	for (int i = 1; i <= mouse; i++) {
		dis[i] = INF;
	}
	dis[start] = 0;
	while(E--) {
		cin >> u >> v >> w;
		adjlist[v].push_back(ii(u,w));
	}
	pq.push(ii(0,start));
	while (!pq.empty()) {
		ii f = pq.top();
		pq.pop();
		int m = f.first;
		int n = f.second;
		if (m == dis[n]) {
			for (int i = 0 ; i < adjlist[n].size(); i++) {
				ii s = adjlist[n][i];
				if (dis[n] + s.second < dis[s.first]) {
					dis[s.first] = dis[n] + s.second;
					pq.push(ii(dis[s.first], s.first));
				}
			}
		}
	}
	for (int i = 1; i <= mouse; i++) {
		if (dis[i] <= toime) {
			ans++;
		}
	}
	cout << ans;
}
