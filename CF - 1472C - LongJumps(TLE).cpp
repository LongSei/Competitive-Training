#include<bits/stdc++.h>
using namespace std;

int test;
int nonumber;
long long arr[10000001];

long long process() {
	long long max = arr[1];
	for (int i = 1; i <= nonumber; i++) {
		int pos = i;
		long long sum = arr[i];
		while (pos < nonumber) {
			sum += arr[pos + arr[i]];
			pos = pos + arr[i];
		}
		if (sum > max) {
			max = sum;
		}
	}
	return max;
}

int main() {
	cin >> test;
	while (test > 0) {
		cin >> nonumber;
		for (int i = 1; i <= nonumber; i++) {
			cin >> arr[i];
		}
		cout << process() << endl;  
		test--;
	}
}
