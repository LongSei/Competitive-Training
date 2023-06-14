#include<bits/stdc++.h>
using namespace std;

int number;
int arr[1000000];
int ans = 0; 
int cnt = 1;

int main() {
	cin >> number;
	for (int i = 0 ; i < number; i++) {
		cin >> arr[i];
	}
	for (int i = 0 ; i < number; i++) {
		if (arr[i] < arr[i + 1]) {
			cnt++; 
		}
		else {
			if (cnt > ans) {
				ans = cnt;
			}
			cnt = 1;
		}
	}
	cout << ans;
}
