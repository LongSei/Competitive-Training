class Solution {
public:
    static const int MOD = 1000000007;
    static const int MAXN = 100000;

    vector<long long> fact = vector<long long>(MAXN + 1, 1);
    vector<long long> invFact = vector<long long>(MAXN + 1, 1);
    unordered_map<int, unordered_map<int, long long>> power_m_minus_1;

    long long fast_pow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    void preprocess() {
        for (int i = 2; i <= MAXN; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[MAXN] = fast_pow(fact[MAXN], MOD - 2, MOD);
        for (int i = MAXN - 1; i >= 1; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }

    long long precompute_power_of_m_minus_1(int m, int n) {
        if (power_m_minus_1.find(m) == power_m_minus_1.end()) {
            power_m_minus_1[m] = unordered_map<int, long long>();
        }
        if (power_m_minus_1[m].find(n) == power_m_minus_1[m].end()) {
            power_m_minus_1[m][n] = fast_pow(m - 1, n, MOD);
        }
        return power_m_minus_1[m][n];
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    Solution() {
        preprocess();
    }

    int countGoodArrays(int n, int m, int k) {
        if (n == 1) {
            return (k == 0) ? m : 0;
        }
        
        long long power = precompute_power_of_m_minus_1(m, n - k - 1);
        long long choose = nCr(n - 1, k);
        long long result = m * choose % MOD;
        result = result * power % MOD;

        return static_cast<int>(result);
    }
};
