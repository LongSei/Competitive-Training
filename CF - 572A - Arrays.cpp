#include<bits/stdc++.h>
using namespace std;
 
int main() {
	long long numb1, numb2;
	cin >> numb1 >> numb2;
	long long lgA, lgB;
	cin >> lgA >> lgB;
	long long A[numb1], B[numb2];
	int countA = 0;
	while (countA < numb1) {
		cin >> A[countA];
		countA++;
	}
	for (int i = 0; i < numb2; i++) {
		cin >> B[i];
	}
	if (A[lgA - 1] < B[numb2 - lgB]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
