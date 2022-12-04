class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
    {
        return 0;
    }

    // Sort the array in ascending order
    std::vector<int> sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());

    // Initialize the maximum difference variable to the difference between the first two elements
    int max_diff = sorted_nums[1] - sorted_nums[0];

    // Iterate through the array, starting at the second element
    for (int i = 1; i < sorted_nums.size(); i++)
    {
        // Calculate the difference between the current element and the previous element
        int diff = sorted_nums[i] - sorted_nums[i-1];
        // Update the maximum difference if necessary
        max_diff = std::max(max_diff, diff);
    }

    return max_diff;
    }
};