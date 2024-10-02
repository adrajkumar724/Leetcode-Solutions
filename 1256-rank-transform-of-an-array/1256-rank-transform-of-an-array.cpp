class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int> st;
        for(auto it:arr)
            st.insert(it);

        map<int,int> mpp;
        int ind=1;

        for(auto it:st){
            mpp[it]=ind;
            ind++;
        }


        for(int i=0;i<arr.size();i++){
            int val=arr[i];

            int rank=mpp[val];

            arr[i]=rank;
        }

        return arr;
            


        
    }
};