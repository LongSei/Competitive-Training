#include<bits/stdc++.h>
using namespace std;

int m;
string s;
int st, en;
int dp[100001];
int cnt = 0;
int main() {
	cin >> s >> m;
	for (int i = 1; i < s.size() ;i++) {
		if (s[i] == s[i - 1]) {
			cnt++;
		}
		dp[i] = cnt;
	}
	while (m--) {
		cin >> st >> en;
		cout << dp[en - 1] - dp[st-1] << endl; 
	}
}
