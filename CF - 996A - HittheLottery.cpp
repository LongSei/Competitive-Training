#include<bits/stdc++.h>
using namespace std;

int main() {
	int money;
	cin >> money;
	int cash[] = {100, 20, 10, 5,1};
	int counti = 0;
	while (money > 0) {
		for (int i = 0 ; i < 5; i++) {
			while (money - cash[i] >= 0) {
				money -= cash[i];
				counti++;
			}
		}
	}
	cout << counti;
}
