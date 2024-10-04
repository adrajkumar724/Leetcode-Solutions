class Solution {
public:
    int mod=1000000007;
    int countPairs(vector<int>& nums) {
        vector<int> vec;
        for(int i=0;i<=21;i++){
            vec.push_back(pow(2,i));
        }

        unordered_map<int,int> mpp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            
            for(int j=0;j<=21;j++){
                int rem=vec[j]-nums[i];
                if(mpp.find(rem)!=mpp.end()){
                    cnt=(cnt+mpp[rem])%mod;

                }
            }
            mpp[nums[i]]++;
        }

        return cnt;


        
    }
};