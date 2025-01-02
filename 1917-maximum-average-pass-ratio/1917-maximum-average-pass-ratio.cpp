class Solution {
    private:
    double calGain(int pass,int total){

        double val1=(pass+1)/(double)(total+1);
        double val2=(pass)/(double)(total);

        return val1-val2;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<pair<double,pair<int,int>>> maxHeap;
        
        int len=classes.size();

        for(int i=0;i<len;i++){

            double gain=calGain(classes[i][0],classes[i][1]);

            maxHeap.push({gain,{classes[i][0],classes[i][1]}});
        }

        while(extraStudents--){

            auto [curGain,classInfo]=maxHeap.top();
            maxHeap.pop();

            int pass=classInfo.first;
            int total=classInfo.second;


            double gain=calGain(pass+1,total+1);

            maxHeap.push({gain,{pass+1,total+1}});

        }

        double totalPassRatio=0;
        while(!maxHeap.empty()){
            auto [_,classInfo]=maxHeap.top();
            maxHeap.pop();

            totalPassRatio+=(double)classInfo.first/classInfo.second;
                   
         }

         return totalPassRatio/len;
        
    }
};