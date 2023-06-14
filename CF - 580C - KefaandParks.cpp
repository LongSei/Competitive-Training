#include<bits/stdc++.h>
using namespace std;

int V,M;
int check[100001];
bool visited[100001] = {false};
vector<vector<int> > adjlist(100001);
int ans = 0;

void dfs(int vertex, int so_meo) {
	visited[vertex] = true;
	int newmeo;
	if (so_meo > M) {
		return;
	}
	
	bool ok = false;
	for (int i = 0; i < adjlist[vertex].size(); i++) {
		if (visited[adjlist[vertex][i]] == false) {
			if (check[adjlist[vertex][i]] == 1) {
				newmeo = so_meo + 1;	
			}
			else {
				newmeo = 0;
			}
			dfs(adjlist[vertex][i], newmeo);
			ok = true;
		}
	}
	if (ok == false) {
		ans++;
	}
}

int main() {
	int a, b;
	cin >> V >> M;
	for (int i = 1; i <= V; i++) {
		cin >>check[i];
	}
	for (int i = 0; i < V - 1; i++) {
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	dfs(1,check[1]);
	cout << ans;
}
