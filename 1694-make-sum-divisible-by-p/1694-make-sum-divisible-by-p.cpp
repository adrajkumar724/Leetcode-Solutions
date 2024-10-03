class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<long long ,int> mpp;
        mpp[0]=-1;

        long long  target=0;
        for(auto it:nums){
            target+=it;
        }
        target=target%p;
        if(target==0)
            return 0;

        int len=nums.size();
        long long  sum=0;

        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%p;

            long long need=(sum-target+p)%p;

            if(mpp.find(need)!=mpp.end()){
                len=min(len,i-mpp[need]);
            }
            mpp[sum]=i;
        }



        if(len==nums.size())
            return -1;
        return len;
    }
};