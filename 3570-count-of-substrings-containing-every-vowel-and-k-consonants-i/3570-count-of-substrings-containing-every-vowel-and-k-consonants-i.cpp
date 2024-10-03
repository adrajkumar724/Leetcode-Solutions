class Solution {
public:
    int countOfSubstrings(string word, int k) {

        int ans=0;

        for(int i=0;i<word.size();i++){
            int a=0,e=0,ic=0,o=0,u=0,cns=0;

            for(int j=i;j<word.size();j++){
                if(word[j]=='a')
                    a++;
                else if(word[j]=='e')
                    e++;
                else if(word[j]=='i')
                    ic++;
                else if(word[j]=='o')
                    o++;
                else if(word[j]=='u')
                    u++;
                else
                    cns++;

                if(cns>k)
                    break;
                
                if(a && e && ic && o && u && cns==k)
                    ans++;                
                
            }
        }
        return ans;
        
    }
};