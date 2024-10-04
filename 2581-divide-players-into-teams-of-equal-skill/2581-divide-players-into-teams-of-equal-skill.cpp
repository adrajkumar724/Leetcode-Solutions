class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        long long arraysum=0;
        for(auto it:skill)
            arraysum+=it;
        
        int n=skill.size()/2;

        if(arraysum%n!=0)
            return -1;
        
        long long  k=arraysum/n;

        unordered_map<long long,int> mpp;

        long long sum=0;

        for(int i=0;i<skill.size();i++){
            long long rem=k-skill[i];

            if(mpp.find(rem)!=mpp.end()){
                long long prod=skill[i]*rem;
                sum+=prod;

                mpp[rem]--;
                if(mpp[rem]==0)
                    mpp.erase(rem);
            }
            else{
                mpp[skill[i]]++;
            }
        }
        if(mpp.size()!=0)
            return -1;
        return sum;

        


    }
};