#include <bits/stdc++.h>
using namespace std;

long long sub, x;
long long arr[100001];
int main() {
	cin >> sub >> x;
	for (int i = 0; i < sub; i++) {
		cin >> arr[i];
	}
	sort(arr,arr+sub);
	long long sum = 0;
	for (int i = 0; i < sub; i++) {
		sum += arr[i] * x;
		if (x > 1) {
			x--;
		}
	}
	cout << sum << endl;
}
