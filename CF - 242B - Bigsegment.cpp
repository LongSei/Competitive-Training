#include<bits/stdc++.h>
using namespace std;

int nosegment;
bool check[1000][1000] = {false};
int counti[1000][1000];
int counto = 1;
int min_begin;
int max_end;

void nhap() {
	for (int i = 1; i <= nosegment; i++) {
		int begi, end;
		cin >> begi >> end;
		check[begi][end] = true;
		counti[begi][end] = counto;
		if (counto > 1) {
			if (begi < min_begin) {
				min_begin = begi;
			}
			if (end > max_end) {
				max_end = end;
			}
		}
		else {
			min_begin = begi;
			max_end = end;
		}
		counto++;
	}
}

int main() {
	cin >> nosegment;
	nhap();
	if (check[min_begin][max_end] == true) {
		cout << counti[min_begin][max_end];
	}
	else {
		cout << -1;
	}
}

