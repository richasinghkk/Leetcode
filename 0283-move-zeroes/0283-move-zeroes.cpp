class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int n=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0){
        //         nums[n]=nums[i];
        //         n++;

        //     }
        // }
        //     for(int i=n;i<nums.size();i++){
        //         nums[i]=0;

        //     }
        // }
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[x]);
                x++;

            }
        }

    }      
    
};