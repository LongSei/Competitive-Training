#include<bits/stdc++.h>
#define INF 1e14
#define int long long
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii>adjlist;
priority_queue<ii, vector<ii>, greater<ii> > pq;
//priority_queue<ii> pq;
int dis[200001];
int V,E;
int u,v,w;
int pre[200001];
vector<int> result;

signed main() {
	cin >> V >> E;
	adjlist.assign(V + 1,vii());
	for (int i = 1; i <= V; i++) {
		dis[i] = INF;
	}
	dis[1] = 0;
	for (int i = 0 ; i < E; i++) {
		cin >> u >> v >> w;
		pre[v] = u;
		adjlist[u].push_back(ii(v,w)); 
		adjlist[v].push_back(ii(u,w));
	}
	pq.push(ii(0,1));
	while (!pq.empty()) {
		ii vu = pq.top();
		pq.pop();
		int m = vu.first;
		int n = vu.second;
		for (int i = 0 ; i < adjlist[n].size(); i++) {
			ii vo = adjlist[n][i];
			if (dis[vo.first] > dis[n] + vo.second) {
				dis[vo.first] = dis[n] + vo.second;
				pre[vo.first] = n;
				pq.push(ii(dis[vo.first], vo.first));
			}
		}
	}
	if (dis[V] == INF) {
		cout << -1;
	}
	else {
        int st = V;
        result.push_back(V);
        while(st != 1){
            int p = pre[st];
            result.push_back(p);
            st = p;
        }
        reverse(result.begin(),result.end());
        for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
	}
}
