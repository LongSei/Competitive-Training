class Solution {
public:
    long long fast_pow(long long n, long long k) {
        long long answer = 1;
        while (k) {
            if (k & 1)
                answer *= n;
            n *= n;
            k >>= 1;
        }
        return answer;
    }

    long long get_number_from_mirror(const string &number, long long base) {
        long long answer = 0;
        for (char c : number) {
            int digit = c - '0';
            if (digit >= base)
                return -1;
            answer = answer * base + digit;
        }
        return answer;
    }

    string get_mirror_from_number(long long number, long long base) {
        if (number == 0)
            return "0";
        string s;
        s.reserve(32);
        while (number > 0) {
            int digit = number % base;
            s.push_back('0' + digit);
            number /= base;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    bool is_palindrome_sv(string_view sv) {
        int left = 0, right = sv.size() - 1;
        while (left < right) {
            if (sv[left] != sv[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool check_number(long long number) {
        string s = to_string(number);
        return is_palindrome_sv(s);
    }

    bool check_mirror(long long number, long long base) {
        string s = get_mirror_from_number(number, base);
        return is_palindrome_sv(s);
    }
    
    bool check_ok(long long number, long long base) {
        return check_mirror(number, base) && check_number(number);
    }

    long long convert_to_palindrome(long long number) {
        string s = to_string(number);
        string rev = s;
        reverse(rev.begin(), rev.end());
        string palindrome;
        palindrome.reserve(s.size() + rev.size());
        palindrome = s + rev;     
        return stoll(palindrome);        
    }

    long long kMirror(int k, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long sum = 0;
        set<long long> count;
        long long maxi = 28111;
        for (int number = 1; number <= maxi; number++) {
            string numStr = to_string(number);
            if (check_ok(number, k) && is_palindrome_sv(numStr))
                count.insert(number);
            if (count.size() > n) {
                auto it = count.end();
                --it;
                maxi = min(maxi, *it);
                count.erase(it);
            }
            long long new_numb = convert_to_palindrome(number);
            if (check_ok(new_numb, k))
                count.insert(new_numb);
            if (count.size() > n) {
                auto it = count.end();
                --it;
                maxi = min(maxi, *it);
                count.erase(it);
            }
            string numb = to_string(new_numb);
            for (char digit = '0'; digit <= '9'; digit++) {
                int mid = numb.size() / 2;
                string new_str = numb.substr(0, mid);
                new_str.push_back(digit);
                new_str.append(numb.substr(mid));
                long long new_add = stoll(new_str);
                if (check_ok(new_add, k))
                    count.insert(new_add);
                if (count.size() > n) {
                    auto it = count.end();
                    --it;
                    maxi = min(maxi, *it);
                    count.erase(it);
                }
            }
            if (count.size() >= n && number >= *count.rbegin())
                break;
        }
        int total_count = 0;
        for (auto &v : count) {
            sum += v;
            total_count++;
            if (total_count == n)
                break;
        }
        return sum;
    }
};
