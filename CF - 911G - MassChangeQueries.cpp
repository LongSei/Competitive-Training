#include <bits/stdc++.h>
using namespace std;
const int BLOCK_SIZE = 800;
const int N = 2e5 + 5;
const int LIM = 100;
int n, number_blocks;
int arr[N];
int lazy[N / BLOCK_SIZE + 1][LIM + 1];
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void push(int id) {
    int L = id * BLOCK_SIZE;
    int R = min(n - 1, (id + 1) * BLOCK_SIZE - 1);
    for (int i = L; i <= R; i++) {
        arr[i] = lazy[id][arr[i]];
    }
    for (int i = 1; i <= 100; i++) {
        lazy[id][i] = i;
    }
}
 
void update_outside(int L, int R, int first_val, int second_val) {
    int id = R / BLOCK_SIZE;
    push(id);
    for (int i = L; i <= R; i++) {
        if (arr[i] == first_val) {
            arr[i] = second_val;
        }
    }
}

void update_block(int id, int first_val, int second_val) {
    for (int i = 1; i <= LIM; i++) {
        if (lazy[id][i] == first_val) {
            lazy[id][i] = second_val;
        }
    }
}
 
void update(int L, int R, int first_val, int second_val) {
    int first_right_left_block = L / BLOCK_SIZE;
    int first_left_right_block = R / BLOCK_SIZE;
    if (first_right_left_block == first_left_right_block) {
        update_outside(L, R, first_val, second_val);
        return;
    }
    for (int i = first_right_left_block + 1; i < first_left_right_block; i++) {
        update_block(i, first_val, second_val);
    }
    update_outside(L, (first_right_left_block + 1) * BLOCK_SIZE - 1, first_val, second_val);
    update_outside(first_left_right_block * BLOCK_SIZE, R, first_val, second_val);
}
 
void init() {
    number_blocks = (n - 1) / BLOCK_SIZE;
    for (int i = 0; i <= number_blocks; i++) {
        for (int j = 1; j <= LIM; j++) {
            lazy[i][j] = j;
        }
    }
}
 
signed main() {
    faster;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init();
    int q; 
    cin >> q;
    for (int Q = 0; Q < q; Q++) {
        int l, r, first_val, second_val;
        cin >> l >> r >> first_val >> second_val;
        l--; r--;
        update(l, r, first_val, second_val);
    }
    for (int i = 0; i <= number_blocks; i++) {
        push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}