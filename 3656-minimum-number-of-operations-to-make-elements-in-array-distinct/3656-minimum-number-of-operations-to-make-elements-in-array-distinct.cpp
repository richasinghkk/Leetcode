#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        int n = nums.size();

        // Repeat the process until the array is empty
        while (!nums.empty()) {
            unordered_set<int> seen;
            bool isDistinct = true;

            // Check if the array has distinct elements
            for (int num : nums) {
                if (seen.count(num)) {
                    isDistinct = false;
                    break;
                }
                seen.insert(num);
            }

            // If the array is distinct, return the operations count
            if (isDistinct) {
                return operations;
            }

            // Remove the first 3 elements or all if fewer than 3 remain
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);

            // Increment the operation counter
            operations++;
        }

        return operations;
    }
};
