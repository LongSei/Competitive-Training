#include <iostream>
#include <algorithm>
#include <cmath>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int len, trv;
long long int A[200002], cnt[1000002];
long long int ans[200002], answer = 0;
int tr, ph,sq;

struct query {
	int l,r,id;
};
query Q[200002];

bool cmp( query A, query B ){
	if( A.l / sq < B.l / sq)
		return true;
	if( A.l / sq > B.l / sq)	
		return false;
	return A.r < B.r;
}

void add(int i) {
	answer += 2 * cnt[A[i]] * A[i] + A[i];
	cnt[A[i]]++;
}

void remove(int i) {
	answer -= 2 * cnt[A[i]] * A[i] - A[i];
	cnt[A[i]]--;
}

long long int query(int i) {
	while (tr < Q[i].l) {
		remove(tr);
		tr++;
	}
	while (tr > Q[i].l) {
		tr--;
		add(tr);
	}
	while (ph < Q[i].r) {
		ph++;
		add(ph);
	} 
	while (ph > Q[i].r) {
		remove(ph);
		ph--;
	}
	return answer;
}

signed main() {
	optimizar_io
	cin >> len >> trv;
	sq = sqrt(len);
	for (int i = 1; i <= len; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= trv; i++) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].id = i;
	}
	sort(Q + 1, Q + trv + 1, cmp);
	for (int i = 1; i <= trv; i++) {
		ans[Q[i].id] = query(i);
	}
	for (int i = 1; i <= trv; i++) {
		cout << ans[i] << endl;
	}
}
