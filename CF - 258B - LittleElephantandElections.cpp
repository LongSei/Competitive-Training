#include<bits/stdc++.h>
using namespace std;

long long giaithua(int i) {
	long long sum = 1;
	for (int a = 1; a <= i; a++) {
		sum *= a;
	}
	return (sum);
}

int main() {
	int a;
	cin >> a;
	string str = "1";
	for (int i = 2; i <= a; i++) {
		stringstream ss;
		ss << i;
		str.append(ss.str());
	}
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '4' || str[i] == '7') {
			cnt++;
		}
	}
	cout << (giaithua(a - cnt) / giaithua(a - cnt - 6) * cnt) % 1000000007;
}
