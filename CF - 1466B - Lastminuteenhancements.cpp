#include<bits/stdc++.h>
using namespace std;

int test;
int number;
int ans = 0;
bool check[1000001];
int str[1000001];

int main() {
	cin >> test;
	while (test--) {
		cin >> number;
		for (int i = 1; i <= number;i++) {
			cin >> str[i];
			check[str[i]] = true;
		}
		sort(str + 1, str + number + 1);
		for (int i = number; i >= 1; i--) {
			if (check[str[i] + 1] == false) {
				str[i] += 1;
				check[str[i]] = true;
				check[str[i] - 1] = false;
			}
			else if (check[str[i]] == false) {
				check[str[i]] = true;
			}
		}
		for (int i = 1; i <= number; i++) {
			if (check[str[i]] == true) {
				ans++;
				check[str[i]] = false;
			}
		}
		cout << ans << endl;
		ans = 0;
	}
}
