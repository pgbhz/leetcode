/*
We get a binary array and can delete one element from it.
Then we want the size of the longest non-empty subarray containing only 1s.
Smells initially like backtracking or dp. Why? Because we can make a choice that
optimizes something. The thing here is that we need to make only one choice. To
remove a zero. And what is the optimal choice? If there is only one subarray of
ones, we just return the length of that subarray. If there are two or more
subarray of ones, in which two of those are separated by only one 0, we clip
that 0. We must delete one element, keep that in mind. If there is only one
element, we return 0. We don't need to return the idx of the clipped element,
just the length of that array. I'm thinking right now of counting the length of
subarrays of ones, but letting one 0 go inside them. How do we do that? That is
very quadratic in nature. Is there a better way? Maybe we iterate like that
beach problem. But where should we start counting again? We should start
counting again from the last seen 0. If there's no seen 0, we just return the
length of the 1s s.a. minus 1.
I tried some sort of disgusting approach. Sliding window will kill it.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int zero_count = 0;
        int max_length = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zero_count++;
            }
            
            while (zero_count > 1) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }
            
            max_length = std::max(max_length, right - left);
            right++;
        }
        
        if (zero_count == 0) {
            return nums.size() - 1;
        }
        
        return max_length;
    }
};

    //     if (nums.size() == 0) {
    //         return 0;
    //     }
    //     int idx = 0;
    //     int last_zero_idx = -1;
    //     int longest_length = 0;     // 5
    //     bool is_processing = false; // true
    //     int start, end;             //  0 1 2 3 4 5 6 7 8
    //     while (idx < nums.size()) { // [0,1,1,1,0,1,1,0,1]
    //         if (!is_processing && nums[idx] == 1) {
    //             start = idx;          // 5
    //             is_processing = true;
    //         } else if (nums[idx] == 0) {
    //             if (is_processing && last_zero_idx > start) {
    //                 end = idx - 1;  // 6
    //                 is_processing = false;  
    //                 longest_length = std::max(longest_length, (end - start)); // max 0 5 -> 5
    //                 idx = last_zero_idx; // 4
    //             } else {
    //                 last_zero_idx = idx;  // 4
    //             }
    //         }
    //         idx++; // 9
    //     }
    //     if (nums[idx-1] == 1) {
    //         end = idx - 1;  // 8
    //     }
    //     longest_length = std::max(longest_length, (end - start)); // 5, 8-5=3 -> 5
    //     return longest_length;
    // }
