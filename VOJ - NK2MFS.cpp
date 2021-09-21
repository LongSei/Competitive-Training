#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 10005;
int n, a[MAX], b[MAX];
vector<ii> N1, N2;
int pos[MAX], t[MAX];

int solve(int pos[]) {
	int timer = 0;
	queue<ii> decore;
	for (int i = 1; i <= n; i++) {
		int nw_timer = timer;
		while (decore.empty() == false && nw_timer < timer + a[pos[i]]) {
			ii nw = decore.front();
			int id = nw.first;
			int need = nw.second;
			if (need + nw_timer <= timer + a[pos[i]]) {
				t[id] = nw_timer + need;
				nw_timer += need;
				decore.pop();
			}
			else {
				decore.front().second -= timer + a[pos[i]] - nw_timer;
				nw_timer = timer + a[pos[i]];
			}
		}
		timer += a[pos[i]];
		decore.push(ii(pos[i], b[pos[i]]));
	}
	while (decore.empty() == false) {
		ii nw = decore.front();
		int id = nw.first;
		int need = nw.second;
		t[id] = timer + need;
		timer += need;
		decore.pop();
	}
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ans = max(t[i], ans);
    }
    return ans;
}

signed main() {
    faster;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] >= b[i]) {
            N2.emplace_back(ii(b[i], i));
        }
        else {
            N1.emplace_back(ii(a[i], i));
        }
    }
    sort(N1.begin(), N1.end());
    sort(N2.begin(), N2.end());
    int cnt = 0;
    for (int i = 0; i < N1.size(); i++) {
        pos[++cnt] = N1[i].second;
    }
    for (int i = N2.size() - 1; i >= 0; i--) {
        pos[++cnt] = N2[i].second;
    }
    cout << solve(pos) << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << pos[i] << " ";
    }
}
