#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int arr[MAX];
int size, quer, a, b;
struct segment{
    int pv,sv,pc,sc,ans;
    void merge(segment a,segment b) {
       	pv=a.pv;
       	pc=a.pc;
       	sv=b.sv;
       	sc=b.sc;
       	if(a.pv == b.pv) {
       		pc=a.pc+b.pc;
   		}
       	if(a.sv == b.sv) {
       		sc=a.sc+b.sc;
       	}
       	ans=max(a.ans,b.ans);
       	if(a.sv == b.pv) {
           ans=max(ans,a.sc+b.pc);
       	}
    }
}seg[4*MAX];

void build(int st, int en, int node) {
	if (st == en) {
		seg[node].pv = seg[node].sv = arr[st];
		seg[node].ans = 1;
		seg[node].pc = seg[node].sc = 1;
		return;
	}
	int mid = (st + en) / 2;
	build(st, mid, node * 2 + 1);
	build(mid + 1, en, node * 2 + 2);
	seg[node].merge(seg[node * 2 + 1], seg[node * 2 + 2]);
}

segment query(int st, int en, int x, int y, int node) {
	segment anss;
	anss.pc = anss.sc = anss.ans = anss.sv = anss.pv = 0;
	if (st > en || st > y || en < x) {
		return anss;
	}
	if (st >= x && en <= y) {
		return seg[node];
	}
	int mid = (st + en) / 2;
	anss.merge(query(st, mid, x, y, node * 2 + 1), query(mid + 1, en, x, y, node * 2 + 2));
	return anss;
}

int main() {
	cin >> size;
	while (size) {
		cin >> quer;
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
		build(0,size-1,0);
		while (quer--) {
			cin >> a >> b;
			cout << query(0, size - 1,a - 1,b - 1, 0).ans << endl;
		}
		cin >> size;
	}
}


