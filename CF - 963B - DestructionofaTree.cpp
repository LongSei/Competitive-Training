#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 2e5 + 5;
int root, n;
vector<int> adjlist[MAX];
bool have_del[MAX];
int siz[MAX];

void del(int pos) {
    have_del[pos] = true;
    cout << pos << endl;
    for (int v : adjlist[pos]) {
        if (have_del[v] == false) {
            del(v);
        }
    }
}
void dfs(int pos) {
    siz[pos] = 1;
    for (int v : adjlist[pos]) {
        dfs(v);
        siz[pos] += siz[v];
    }
    if (siz[pos] % 2 == 0) {
        del(pos);
    }
}

signed main() {
    faster;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == 0) {
            root = i;
        }
        else {
            adjlist[x].emplace_back(i);
        }
    }
    if (n % 2 == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    dfs(root);   
    del(root);
}
