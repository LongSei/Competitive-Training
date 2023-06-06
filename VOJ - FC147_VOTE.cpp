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
const int MAX = 5e5 + 5;
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
int numberStudent;
priority_queue<ii, vector<ii>, greater<ii>> studentVote[MAX]; // (Cost, ID Student)
int highestVoteStudentID = 0; 
int highestVoteStudentPrice = 0;
int amountVoteStudent[MAX];
map<int, bool> vote[MAX];
priority_queue<ii, vector<ii>, greater<ii>> allVote;
priority_queue<ii> studentRanking; // (AmountVote, ID student)
bool check[MAX];
int totalCost = 0;

void resetStudentRanking() {
	auto fr = studentRanking.top();
	while (fr.first != amountVoteStudent[fr.second]) {
		studentRanking.pop();
		studentRanking.push(ii(amountVoteStudent[fr.second], fr.first));
		fr = studentRanking.top();
	}
}

void solve() {
	cin >> numberStudent;
	int ans = INF; 
	for (int i = 1; i <= numberStudent; i++) {
		int student, cost; cin >> student >> cost;
		amountVoteStudent[student] += 1;
		if (student == 1) {
			continue;
		}
		studentVote[student].push(ii(cost, i)); 
		allVote.push(ii(cost, student));
	}
	for (int i = 1; i <= numberStudent; i++) {
		studentRanking.push(ii(amountVoteStudent[i], i));
	}
	highestVoteStudentID = studentRanking.top().second;
	// cout << "HIGHEST VOTE: " << highestVoteStudentID << " " << amountVoteStudent[highestVoteStudentID] << endl;
	if (highestVoteStudentID == 1) {
		cout << 0 << endl;
		return;
	}
	while (amountVoteStudent[1] <= amountVoteStudent[highestVoteStudentID]) {
		resetStudentRanking();
		// cout << "DEBUG AMOUNT" << endl;
		// for (int i = 1; i <= numberStudent; i++) {
		// 	cout << amountVoteStudent[i] << " ";
		// }
		// cout << endl;
		// Check the highest vote student
		auto highestVoteStudent = studentRanking.top();
		highestVoteStudentID = highestVoteStudent.second;
		highestVoteStudentPrice = studentVote[highestVoteStudentID].top().first;

		// Check the cheapest student
		while (check[allVote.top().second] == true) {
			check[allVote.top().second] = false;
			allVote.pop();
		}
		auto cheapestVote = allVote.top();
		int cheapestVotePrice = cheapestVote.first;
		int cheapestVoteID = cheapestVote.second;

		// Check the value 
		int valueCheapest = cheapestVotePrice * 2;
		int valueHighestVote = highestVoteStudentPrice;

		// cout << "Value Cheap/CheapInfo: " << valueCheapest << " | " << cheapestVoteID << " | " << cheapestVotePrice << endl;
		// cout << "Value Highest/HighestInfo: " << valueHighestVote << " | " << highestVoteStudentID << " | " << highestVoteStudentPrice << endl;
		// cout << endl;

		if (((amountVoteStudent[1] + 1) > amountVoteStudent[highestVoteStudentID])) {
			ans = min(ans, totalCost + cheapestVotePrice);
		} 
		if (((amountVoteStudent[1] + 2) > amountVoteStudent[highestVoteStudentID])) {
			ans = min(ans, totalCost + highestVoteStudentPrice);
		}

		// If the highest vote student is difference from the cheapest price
		if (cheapestVoteID != highestVoteStudentID) {
			
			// Choose Cheapest 
			if (valueCheapest < valueHighestVote) {
				// cout << "CHOOSE CHEAPEST" << endl;
				totalCost += cheapestVotePrice;
				amountVoteStudent[cheapestVoteID] -= 1;
				amountVoteStudent[1] += 1;

				studentVote[cheapestVoteID].pop();
				allVote.pop();
			}
			// Choose Highest
			else {
				// cout << "CHOOSE HIGHEST" << endl;
				totalCost += highestVoteStudentPrice;
				amountVoteStudent[1] += 1;
				amountVoteStudent[highestVoteStudentID] -= 1;

				studentVote[highestVoteStudentID].pop();
				check[highestVoteStudentID] = true;

				auto frStudentRanking = studentRanking.top();
				int frStudentRankingID = frStudentRanking.second;
				int frStudentRankingAmount = frStudentRanking.first - 1;
				studentRanking.pop();
				studentRanking.push(ii(frStudentRankingAmount, frStudentRankingID));
			}
		}

		// If the highest student is the same as the cheapest price
		else {
			// cout << "CHOOSE SAME" << endl;
			totalCost += highestVoteStudentPrice;
			amountVoteStudent[highestVoteStudentID] -= 1;
			amountVoteStudent[1] += 1;

			studentVote[highestVoteStudentID].pop();
			allVote.pop();

			auto frStudentRanking = studentRanking.top();
			int frStudentRankingID = frStudentRanking.second;
			int frStudentRankingAmount = frStudentRanking.first - 1;
			studentRanking.pop();
			studentRanking.push(ii(frStudentRankingAmount, frStudentRankingID));
		}
		// cout << endl;
	}
	cout << min(ans, totalCost) << endl;
}

signed main() {
	faster;
	int test = 1;
	// cin >> test; 
	while (test--) {
		solve();
	}
}
