class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue <int> pq;
        for(auto it : nums) pq.push(it);
        for(int i = 0; i < k; i++){
            int val = pq.top();
            ans += val;
            pq.pop();
            pq.push(ceil((double)val/3));
        }
        return ans;
    }
};