#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e4 + 1;
const int MINC = -2e9;
int n, a[5][MAX], fr[9][9], f[9][MAX];

void inp() {
    // Hàm nhập dữ liệu đầu vào

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

int getbit(int k, int x) {
    // hàm sử dụng để lấy bit thứ k của số x

    return (x >> (k - 1)) & 1;
}

int ok(int x, int y) {
    // hàm sử dụng để kiểm tra các bit ở vị trí thứ i (1 <= i <= 4) của hai số x, y có luôn khác nhau hay không

    int bitx[5], bity[5];
    for (int i = 1; i <= 4; i++) {
        bitx[i] = getbit(i, x);
        bity[i] = getbit(i, y);
    }
    // Bước 1: lấy bit ở các vị trí i cảu hai số x, y


    for (int i = 1; i <= 4; i ++) {
        if ((bitx[i] & bity[i]) == 1) {
            return 0;
        }
    }
    return 1;
    // Bước 2: so sánh nếu có ít nhất 1 vị trí giống trả về 0(false), còn lại trả về 1(true
}

int value(int x, int y) {
    // Hàm sử dụng để trả về giá trị khi lấy các số ở cột y theo trạng thái x

    // Bước 1: Cập nhật trạng thái
    int bit[5], sum = 0;
    for (int i = 1; i <= 4; i++) {
        bit[i] = getbit(i, x);
    }

    // Bước 2: Nếu bit = 1 thì lấy, còn bit = 0 thì không lấy
    for (int i = 1; i <= 4; i++) {
        if (bit[i] == 1) {
            sum += a[i][y];
        }
    }
    return sum;
}

int bitmask() {
    // Hàm chính đẻ giải quyết bài toán

    // Bước 1: Khởi tạo mảng d (khi biểu diễn dưỡi bit là tập hợp các trạng thái)
    int d[] = {0,1,2,4,5,8,9,10}, res = MINC;

    // Bước 2: Kiểm tra các cặp trạng thái có phù hợp hay không
    for (int i = 0; i < 8; i++) {
        for (int j = 0 ; j < 8; j++) {
            fr[i][j] = ok(d[i], d[j]);
        }
    }

    // Bước 3: Bắt đầu tính toán
    // Bước 3.1: Quy hoạch động trên toàn bộ hình (xét tất cả các cột i trong mọi trạng thái)
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            int t = MINC;
            for (int k = 0; k < 8; k++) {
                // Bước 3.2: kiểm tra hai trạng 2 trạng thái j, k có phù hợp với nhau hay không, xét k (ở trạng thái k cột i - 1 đạt giá trị lớn nhất)
                if (fr[j][k] == 1 && f[k][i - 1] > t) {
                    t = f[k][i - 1];
                }

            }
            // Bước 3.3: tìm được giá trị của cột i trong trạng thái j
            f[j][i] = t + value(d[j], i);
        }
    }

    // Bước 4: Tìm trạng thái i, sao cho cột n đạt MAX
    for (int i = 0; i < 8; i++) {
        res = max(res, f[i][n]);
    }
    return res;
}

signed main() {
    inp();
    cout << bitmask();
}