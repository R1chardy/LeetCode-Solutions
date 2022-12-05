class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
         // if the input array is empty, there are no permutations
  if (nums.empty()) return {};

  // if the input array has only one element, there is only one permutation
  if (nums.size() == 1) return {nums};

  // initialize an array to store the permutations
  std::vector<std::vector<int>> result;

  // loop through the input array
  for (int i = 0; i < nums.size(); i++) {
    // create a new array that does not contain the current element
    std::vector<int> remaining;
    remaining.reserve(nums.size() - 1);
    for (int j = 0; j < nums.size(); j++) {
      if (i != j) remaining.push_back(nums[j]);
    }

    // compute all the permutations of the remaining elements
    std::vector<std::vector<int>> subPermutations = permute(remaining);

    // add the current element to each of the permutations of the remaining elements
    // and store the result in the `result` array
    for (const auto& permutation : subPermutations) {
      result.push_back({nums[i]});
      result.back().insert(result.back().end(), permutation.begin(), permutation.end());
    }
  }

  // return the array of permutations
  return result;
    }
};