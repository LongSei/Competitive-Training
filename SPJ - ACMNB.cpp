#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 800005
int number;
typedef pair<int, int> ii;
pair<int, int> les[MAX];
int result = 0;

bool cmp(ii a, ii b) {
	return a.first - a.second < b.first - b.second;
}

signed main() {
	scanf("%d", &number);
	number *= 2;
	for (int i = 1; i <= number; i++) {
		scanf("%d%d", &les[i].first, &les[i].second);
	}
	sort(les + 1, les + 1 + number, cmp);
	for (int i = 1; i <= number / 2; i++) {
		result += les[i].first;
	}
	for (int i = (number / 2) + 1; i <= number; i++) {
		result += les[i].second;
	}
	printf("%d", result);
}
