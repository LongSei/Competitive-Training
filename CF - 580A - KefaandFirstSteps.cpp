#include<bits/stdc++.h>
using namespace std;
int nonumber, j;
int arr[1000];
 
int day(int a) {
	int sum = 1;
	for (int i = a; i <= nonumber; i++) {
		j = i + 1;
		if (arr[i] <= arr[j]) {
			sum++;
		}
		else {
			break;
		}
	}
	return sum;
}
 
int main() {
	int ans = 0;
	cin >> nonumber;
	for (int i = 1; i <= nonumber; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= nonumber; i++) {
		if (day(i) > ans) {
			ans = day(i);
		}
	}
	cout << ans;
}
