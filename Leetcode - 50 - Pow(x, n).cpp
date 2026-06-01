class Solution {
public:
    double myPow(double x, int n) {
        bool neg = (n < 0); 
        double answer = 1;
        while (n) {
            if (n % 2 == 0) {
                x = x * x;
                n /= 2;
            } else {
                answer = (neg ? (answer / x) : (answer * x));
                n += (neg ? 1 : -1);
            }
        }
        return answer;
    }
};
