#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n, x[100010], y[100010], z[100010], pre[100010], res = 0;
struct edge {int u, v, cost;};
vector<ii> v;
vector<edge> e;
bool cmp(edge a, edge b) {return a.cost < b.cost;}
void addedge() {
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++) {
		edge new_edge;
		new_edge.u = v[i - 1].second;
		new_edge.v = v[i].second;
		new_edge.cost = v[i].first - v[i - 1].first;
		e.push_back(new_edge);
	}
	v.clear();
}
void makeset(int k)
{
     pre[k] = k;
};
 
int root(int k)
{
    if (k != pre[k]) pre[k] = root(pre[k]);
    return pre[k];
};
 
void connect(int i,int j)
{
    int i1 = root(i),j1 = root(j);
    pre[i1] = j1;
};
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> z[i];
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(ii(x[i], i));
	}
	addedge();
	for (int i = 1; i <= n; i++) {
		v.push_back(ii(y[i], i));
	}
	addedge();
	for (int i = 1; i <= n; i++) {
		v.push_back(ii(z[i], i));
	}
	addedge();
	sort(e.begin(), e.end(), cmp);
	for (int i = 1; i <= n; i++) {
		makeset(i);
	}
    for (int i = 0; i < e.size(); i++)
      	if (root(e[i].u) != root(e[i].v)) {
        	connect(e[i].u,e[i].v);  res += e[i].cost;
      	}
    cout << res;
}
