#include<iostream>
using namespace std;
long int timeread[100100];
long int ans = 0;
long int i,j,sum,counti,nobooks,minute;
 
int main() {
	cin >> nobooks >> minute;
	for (i = 1; i <= nobooks; i++) {n
		cin >> timeread[i];
	}
	for (i = 1; i <= nobooks; i++) {
		sum = timeread[i];
		if (sum < minute) {
			counti = 1;
		}
		for (j = i + 1; j <= nobooks; j++) {
			if (sum + timeread[j] <= minute) {
				sum += timeread[j];
				counti++;
			}
			else {
				break;
			}
		}
		if (counti > ans) {
			ans = counti;
		}
	}
	cout << ans << endl;
	return 0;
}

