class Solution {
public:
  int rob(vector<int> &nums) {
    // maximum amount of money you can rob up to house i
    vector<int> dp;

    // setting up our base case
    dp.push_back(nums[0]);

    // base case
    if (nums.size() == 1) {
      return dp[0];
    }

    // populate the array
    dp.push_back(std::max(nums[0], nums[1]));
    for (int i=2; i<nums.size(); ++i) {
      dp.push_back(std::max(nums[i] + dp[i-2], dp[i-1]));
    }

    return dp[dp.size()-1];
  }
};
