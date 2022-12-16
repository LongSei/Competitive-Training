#include<bits/stdc++.h>
using namespace std;

// DEBUG TEMPLATE //
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template<typename T>
void __print(deque<T> dq) {cerr << "{"; while (dq.empty() == false) {auto fr = dq.front(); __print(fr); dq.pop_front(); if (dq.empty() == false) {cerr << ",";}} cerr << "}";}
template<typename T>
void __print(queue<T> q) {cerr << "{"; while (q.empty() == false) {auto fr = q.front(); __print(fr); q.pop(); if (q.empty() == false) {cerr << ",";}} cerr << "}";}
template<typename T>
void __print(stack<T> st) {cerr << "{"; while (st.empty() == false) {auto fr = st.top(); __print(fr); st.pop(); if (st.empty() == false) {cerr << ",";}} cerr << "}";}
template<typename T>
void __print(priority_queue<T> q) {cerr << "{"; while (q.empty() == false) {auto fr = q.top(); __print(fr); q.pop(); if (q.empty() == false) {cerr << ",";}} cerr << "}";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// TEMPLATE FOR SOLVING PROBLEM // 
// #define endl '\n'
#define int long long
#define ii pair<int, int>
#define pi_ii pair<int, ii>
#define pii_i pair<ii, int>
#define real long double
#define p_queue priority_queue 
#define pb push_back
#define lb lower_bound  // First element NOT LESS than val
#define ub upper_bound  // First element GREATER than val
#define all(x) (x).begin(), (x).end()
#define min(x, y) (((x) < (y))?(x):(y))
#define max(x, y) (((x) > (y))?(x):(y))
#define foru(i, st, ed, range) for(int i = st; i <= ed; i = i + range)
#define ford(i, st, ed, range) for(int i = st; i >= ed; i = i + range)
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 1e15 + 5;
const int MAX = 2e5 + 5;
const int mod = 1e9 + 7;

// TEMPLATE FOR DATA STRUCTURE AND ALGORITHM //	
int fast_pow(int n, int k) {
	int res = 1;
    while (k) {
        if (k & 1) {res = (res * n) % mod; k -= 1;}
        else {n = (n * n) % mod; k >>= 1;}
    }
    return res;
}
int GCD(int a, int b) {return b ? GCD (b, a % b) : a;}
int LCM(int a, int b) {return a * b / GCD(a, b);}
int GetBit(int k, int n) {return (n & (1 << k)) >> k;}

// MAIN CODE //
struct Quer {
	int l = 0, r = 0, value = 0;
} qu[MAX];
int n, q;
Quer Q(int l, int r, int value) {
	Quer result;
	result.l = l;
	result.r = r;
	result.value = value;
	return result;
}

struct Node {
    int lazy;
    int val;
} st[MAX * 4];

void push_down(int v, int tl, int tr) {
    if (st[v].lazy != 0) {
        int t = st[v].lazy;
        st[v].val += (tr - tl + 1) * t;
        st[v].lazy = 0;
        if (tl != tr) {
            st[v * 2 + 1].lazy += t;
            st[v * 2 + 2].lazy += t;
        }
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    push_down(v, tl, tr);
    if (tl > r || tr < l) {
        return;
    }
    if (l <= tl && tr <= r) {
        st[v].val += (tr - tl + 1) * val;
        if (tl != tr) {
            st[v * 2 + 1].lazy += val;
            st[v * 2 + 2].lazy += val;
        }
        return;
    }
    int mid = (tl + tr) >> 1;
    update(v * 2 + 1, tl, mid, l, r, val);
    update(v * 2 + 2, mid + 1, tr, l, r, val);
    st[v].val = st[v * 2 + 1].val + st[v * 2 + 2].val;
}

int query(int v, int tl, int tr, int l, int r) {
    push_down(v, tl, tr);
    if (tl > r || tr < l) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return st[v].val;
    }
    int mid = (tl + tr) >> 1;
    int ll = query(v * 2 + 1, tl, mid, l, r);
    int rr = query(v * 2 + 2, mid + 1, tr, l, r);
    return (ll + rr);
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		update(1, 1, n, i, i, x);
	}
	for (int i = 1; i <= q; i++) {
		int type; cin >> type; 
		int l, r, val; 
		if (type == 1) {
			cin >> l >> r >> val;
			qu[i] = Q(l, r, val);
			update(1, 1, n, l, r, val);
		}
		if (type == 2) {
			int pos; cin >> pos;
			qu[i] = Q(qu[pos].l, qu[pos].r, -qu[pos].value);
			update(1, 1, n, qu[pos].l, qu[pos].r, -qu[pos].value);
		}
		if (type == 3) {
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}
		// cout << "DEBUG" << endl;
		// for (int i = 1; i <= n; i++) {
		// 	query(1, 1, n, i, i);
		// }
		// cout << endl << endl;
	}
}

signed main() {
	faster;
	int test = 1;
	// freopen("test.inp", "r", stdin);
	// freopen("ans1.txt", "w", stdout);
	// cin >> test; 
	while (test--) {
		solve();
	}
}
