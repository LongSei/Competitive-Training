class Solution {
public:
    const static int MAX_INDEX = 3 * 100000 + 1;
    priority_queue<long long, vector<long long>, greater<long long>> pq; 
    long long minValue[MAX_INDEX]; 
    long long maxValue[MAX_INDEX]; 
    long long minimumDifference(vector<int>& nums) {
        // To find the minimum difference of sum_1 and sum_2 then: 
        // - Find the min sum_1 
        // - Find the max sum_2 
        // -> Pivot at index i

        int max_size = nums.size(); 
        int n = max_size / 3; 

        long long acc = 0; 
        for (int index = 0; index < n; index++) {
            pq.push(-(long long)nums[index]);
            acc += (long long)nums[index];
        }
        minValue[n - 1] = acc;
        for (int index = n; index < max_size; index++) {
            pq.push(-(long long)nums[index]);
            acc += (long long)nums[index];
            acc += pq.top(); pq.pop(); 
            minValue[index] = acc;
        }
        while (pq.empty() == false) {
            pq.pop();
        }

        acc = 0;
        for (int index = max_size - 1; index >= max_size - n; index--) {
            pq.push((long long)nums[index]);
            acc += (long long)nums[index];
        }
        maxValue[max_size - n] = acc; 
        for (int index = max_size - n - 1; index >= 0; index--) {
            pq.push((long long)nums[index]);
            acc += (long long)nums[index];
            acc -= pq.top(); pq.pop(); 
            maxValue[index] = acc;
        }

        long long answer = 1e15 + 5;
        for (int index = n - 1; index <= max_size - n - 1; index++) {
            answer = min(answer, minValue[index] - maxValue[index + 1]);
        }
        return answer;
    }
};
