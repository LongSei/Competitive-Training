#include<bits/stdc++.h>
using namespace std;

int main() {
	int arr[1000];
	int nonumber;
	cin >> nonumber;
	for (int i = 1; i <= nonumber; i++) {
		cin >> arr[i];
	}
	int suma = 0;
	int sumb = 0;
	int counti = 1;
	int i = 1;
	while (i <= nonumber) {
		if (arr[i] <= arr[nonumber]) {
			if (counti % 2 == 1) {
				suma += arr[nonumber];
				nonumber--;
				counti++;
			}
			else {
				sumb += arr[nonumber];
				nonumber--;
				counti++;
			}
		}
		else {
			if (counti % 2 == 1) {
				suma += arr[i];
				i++;
				counti++;
			}
			else {
				sumb += arr[i];
				i++;
				counti++;
			}
		}
	}
	cout << suma << " " << sumb << endl;
}
