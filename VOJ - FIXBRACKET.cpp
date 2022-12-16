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
const int MAX = 1e6 + 5;
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
int n, q; 
char str[MAX];
int masking(char x) {
	return ((x == '(' || x == ')') ? 1 : 0);
}
struct Node {
	int type;
	int amount;
	Node () {}
	Node (int t, int l) {
		type = t;
		amount = l;
	}
} st[MAX * 4];

Node merge(Node ll, Node rr) {
	int type_bl = ll.type;
	int type_br = rr.type;
	Node result;
	if (type_bl == -1 && type_br == -1) {
		result.type = -1;
		result.amount = 0;
		return result;
	}
	else if (type_bl == -1) {
		return rr;
	}
	else if (type_br == -1) {
		return ll;
	}
	int type_el = (ll.amount % 2 == 0 ? (1 - ll.type) : ll.type);
	int type_er = (rr.amount % 2 == 0 ? (1 - rr.type) : rr.type);
	if (type_br == type_el) {
		if (ll.amount == rr.amount) {
			result.type = -1;
			result.amount = 0;
		}
		else if (ll.amount > rr.amount) {
			result.type = type_bl;
			result.amount = ll.amount - rr.amount;
		}
		else {
			result.type = type_bl ^ 1;
			result.amount = rr.amount - ll.amount;
		}
	}
	else {
		result.type = type_bl;
		result.amount = ll.amount + rr.amount;
	}
	return result;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		st[v].type = masking(str[tl]);
		st[v].amount = 1;
		return;
	}
	int mid = (tl + tr) >> 1;
	build(v * 2 + 1, tl, mid);
	build(v * 2 + 2, mid + 1, tr);
	st[v] = merge(st[v * 2 + 1], st[v * 2 + 2]);
}

Node query(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l) {
		Node result;
		result.type = -1;
		result.amount = 0;
		return result;
	}
	if (l <= tl && tr <= r) {
		return st[v];
	}
	int mid = (tl + tr) >> 1;
	Node ll = query(v * 2 + 1, tl, mid, l, r);
	Node rr = query(v * 2 + 2, mid + 1, tr, l, r);
	return merge(ll, rr);
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
	}
	build(1, 1, n);
	// for (int i = 1; i <= n; i++) {
	// 	cout << query(1, 1, n, i, i).type << " ";
	// }
	// cout << endl;
	for (int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;
		Node ans = query(1, 1, n, l, r);
		// debug(ans.type, ans.amount);
		cout << (ans.amount) / 2 << endl;
	}
}

signed main() {
	faster;
	int test = 1;
	cin >> test; 
	while (test--) {
		solve();
	}
}