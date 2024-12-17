class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==t){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {-1,-1};


        // unordered_map<int,int>m;
        // for(int i=0;i<n;i++){
        //     int x=nums[i];
        //     int y=t-x;
        //     if(m.find(y)!=m.end()){
        //         return {i,m[y]};
        //     }
        //     m[nums[i]]=i;
        // }
        // return {-1,-1};

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        int s=0;
        int e=n-1;
        while(s<e){
            int sum=v[s].first+v[e].first;
            if(sum==t) return {v[s].second,v[e].second};
            else if(sum>t) e--;
            else s++;
        }
        return {-1,-1};
    }
};