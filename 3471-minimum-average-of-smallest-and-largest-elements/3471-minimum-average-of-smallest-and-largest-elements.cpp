class Solution {
public:
    double minimumAverage(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<double>average;
        int n=nums.size();
       for(int i=0;i<n/2;i++){
        double ans=(nums[i]+nums[n-i-1])/2.0;
        average.push_back(ans);
       }
       sort(average.begin(),average.end());
       return average[0];
        
    }
};