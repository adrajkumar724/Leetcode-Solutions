class Solution {
public:
    bool isSubString(string a, string b){
        if(a.size() > b.size()) return false;
        int j = 0;
        for(int i = 0; i < b.size(); i++){
            int matchLen = 0;
            for(int j = 0; j < a.size(); j++){
                if(i + j < b.size() && b[i + j] == a[j] ) matchLen++;
            }
            if(matchLen == a.size()) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(isSubString(words[i],words[j])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};