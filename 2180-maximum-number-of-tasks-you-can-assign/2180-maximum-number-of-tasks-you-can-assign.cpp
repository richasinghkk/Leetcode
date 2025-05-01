class Solution {
public:
    // Helper function to check if we can assign 'mid' number of tasks
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int pillsUsed = 0;
        // Take the strongest 'mid' workers
        multiset<int> st(begin(workers), begin(workers) + mid);

        // Go through the 'mid' most difficult tasks (from the end of sorted tasks)
        for (int i = mid - 1; i >= 0; i--) {
            int req = tasks[i];
            auto it = prev(st.end());  // Strongest available worker
            if (*it >= req) {
                st.erase(it);
            } else {
                if (pillsUsed >= pills) return false;
                // Try to find a worker who can complete the task with a pill
                auto it2 = st.lower_bound(req - strength);
                if (it2 == st.end() || *it2 + strength < req) {
                    return false;
                }
                st.erase(it2);
                pillsUsed++;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();

        // Sort tasks in ascending and workers in descending order
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());

        int left = 0, right = min(m, n);
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(tasks, workers, pills, strength, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
