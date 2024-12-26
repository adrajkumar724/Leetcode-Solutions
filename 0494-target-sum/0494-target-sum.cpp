class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        int totalSum=0;
        totalSum=accumulate(nums.begin(),nums.end(),totalSum);

        int sum=totalSum-target;

        if(sum%2)
            return 0;

        if(sum<0)
            return 0;

        sum/=2;

        vector<vector<int>> dp(n,vector<int>(sum+1,0));

        for(int i=0;i<n;i++)
            dp[i][0]=1;
        
        if(nums[0]==0)
            dp[0][0]=2;

        if(nums[0]!=0 && nums[0]<=sum)
            dp[0][nums[0]]=1;

        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=sum;tar++){
                int notpick=dp[ind-1][tar];

                int pick=0;
                if(nums[ind]<=tar)
                    pick=dp[ind-1][tar-nums[ind]];


                dp[ind][tar]=pick+notpick;
            }
        }

        return dp[n-1][sum];
        


        
    }
};