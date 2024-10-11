class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>> arrivalTime; //{arrival time, index};
        int n = times.size();
        for(int i = 0; i < n; i++){
            arrivalTime.push_back({times[i][0],i});
        }
        sort(arrivalTime.begin(),arrivalTime.end()); // sort based on the arrival time

        priority_queue<int, vector<int>, greater<int>> availableChairs;// {available chairs}
        //Initially all chairs are available
        for(int i = 0; i < n; i++)availableChairs.push(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> occupiedChairs; //{leavingTime, chair}

        for(auto &event : arrivalTime){
            int time = event.first;
            int index = event.second;
            while(!occupiedChairs.empty() && occupiedChairs.top().first <= time){
                availableChairs.push( occupiedChairs.top().second);
                // occupiedChairs.top().second => freed chair
                occupiedChairs.pop();
            }
            int availableChair = availableChairs.top();
            availableChairs.pop();

            int leavingTime = times[index][1];
            if(index == targetFriend) return availableChair;
            occupiedChairs.push({leavingTime,availableChair});

        }
        return -1; // if not present
        
    }
};