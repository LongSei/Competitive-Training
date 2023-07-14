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
const int MAX = 3e5 + 5;
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
string s1, s2;
void solve() {
    cin >> s1 >> s2;
    int ans = INF;
    for (int len = 0; len <= min(s1.size(), s2.size()); len++) {
        bool isok = true;
        int i = s1.size() - len;
        int j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] != s2[j]) {
                isok = false;
            }
            i += 1;
            j += 1;
        } 
        if (isok == true) {
            ans = min(ans, s1.size() + s2.size() - len);
        }
    }
    cout << ans << endl;
}

signed main() {
	faster;
	int test = 1;
	// cin >> test; 
	while (test--) {
		solve();
	}
}