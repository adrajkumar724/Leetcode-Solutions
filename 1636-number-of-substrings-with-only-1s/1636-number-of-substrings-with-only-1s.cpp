class Solution {
public:

    int mod=1e9+7;
    int numSub(string s) {
        int start=0,end=0;
        int len=s.size();
        int cnt=0;

        while(end<len){
            if(s[end]=='0'){
                end++;
                start=end;
                continue;
            }

            cnt+=(end-start+1)%mod;
            cnt=cnt%mod;
            end++;
        }

        return cnt;
        
    }
};