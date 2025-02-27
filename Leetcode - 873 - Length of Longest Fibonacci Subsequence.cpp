class Solution {
public:
    int largest_length[1005][1005]; 
    int find_index_of_number(vector<int>& arr, int value) {
        int left = 0;
        int right = arr.size() - 1; 

        if (value <= 0) {
            return -1;
        }

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (arr[mid] > value) {
                right = mid - 1;
            } else if (arr[mid] < value) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int arr_length = arr.size(); 
        for (int next_num_index = 0; next_num_index <= arr_length - 1; next_num_index++) {
            int next_num_value = arr[next_num_index];

            for (int last_num_index = 0; last_num_index < next_num_index; last_num_index++) {
                int last_num_value = arr[last_num_index];
                int prev_last_num_value = next_num_value - last_num_value;
                int prev_last_num_index = find_index_of_number(arr, prev_last_num_value);
                
                largest_length[last_num_index][next_num_index] = 2;
                if (prev_last_num_index == -1 || prev_last_num_index > last_num_index) {
                    continue;
                }

                largest_length[last_num_index][next_num_index] = max(largest_length[last_num_index][next_num_index], largest_length[prev_last_num_index][last_num_index] + 1);
            }
        }

        int answer = min(arr_length, 2);
        for (int last_num_index = 0; last_num_index < arr_length; last_num_index++) {
            for (int prev_last_num_index = 0; prev_last_num_index < last_num_index; prev_last_num_index++) {
                answer = max(answer, largest_length[prev_last_num_index][last_num_index]);
            }
        }

        return (answer <= 2 ? 0 : answer);
    }
};
