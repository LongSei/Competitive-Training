#include<bits/stdc++.h>
using namespace std;

int teama[100000];
int teamb[100000];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> teama[i];
	}
	for (int i = 0 ; i < n; i++) {
		cin >> teamb[i];
	}
	long long dp2[n], dp1[n], dp0[n];
	dp2[0] = 0;
	dp1[0] = teamb[0];
	dp0[0] = teama[0];
	for (int i = 1; i < n; i++) {
		dp2[i] = max(max(dp0[i - 1], dp1[i - 1]), dp2[i - 1]);
		dp1[i] = max(dp2[i - 1], dp0[i - 1]) + teamb[i];
		dp0[i] = max(dp2[i - 1], dp1[i - 1]) + teama[i];
	}
	cout << max(dp0[n - 1], max(dp1[n - 1], dp2[n - 1]));
}
